#include "MainWindow.h"

#include "BuyMenu.h"
#include "GameDialog.h"
#include "UnitActionMenu.h"
#include "UnitUnloadMenu.h"

#include "game/game.h"
#include "game/game_controller.h"

#include <boost/bind.hpp>

#include <QMessageBox>

using namespace aw;

MainWindow::MainWindow(QMainWindow* parent)
  : QMainWindow(parent),
	graphicsScene(new GameScene(this)) {
	setupUi(this);

	mapView->setScene(graphicsScene);
	
	//Connect slots
	connect(actionNewGame, SIGNAL(triggered()), this, SLOT(newGame()));
	connect(actionEndTurn, SIGNAL(triggered()), this, SLOT(endTurn()));
}


void MainWindow::newGame() {
	GameDialog gameDialog;
	if(gameDialog.exec() == QDialog::Accepted) { 
		game::ptr game(new aw::game());

		game->set_funds_per_building(gameDialog.fundsPerBuilding());
		game->set_initial_funds(gameDialog.initialFunds());

		game->load_map(gameDialog.mapFile());


		gameController = game_controller::ptr(new game_controller);

		graphicsScene->reset();
		graphicsScene->signalClicked().connect(boost::bind(&aw::game_controller::click, gameController, _1, _2));
		graphicsScene->signalFocusChanged().connect(boost::bind(&aw::game_controller::mouse_hover_changed, gameController, _1));
		gameController->signal_scene_change().connect(boost::bind(&GameScene::setScene, graphicsScene, _1));

		//Connect the menu-callbacks
		gameController->signal_show_unit_action_menu().connect(boost::bind(&UnitActionMenu::showActionMenu, this, _1));
		gameController->signal_show_buy_menu().connect(boost::bind(&BuyMenu::showBuyMenu, this, _2, _1));
		gameController->signal_show_unload_menu().connect(boost::bind(&UnitUnloadMenu::showUnloadMenu, this, _1));

		//Connect callbacks like game-won etc.
		game->signal_game_finished().connect(boost::bind(&MainWindow::gameFinished, this, _1));

		actionEndTurn->setEnabled(true);

		gameController->start_game(game);
		mapView->setEnabled(true);
	}
}

void MainWindow::endTurn() {
	gameController->end_turn();
	gameController->start_turn();
}

void MainWindow::gameFinished(const aw::player::ptr& p) {
  actionEndTurn->setEnabled(false);
  gameController.reset();
  mapView->setEnabled(false);

  QMessageBox::information(this, "Game is finished!", QString("The %1 player has won!").arg(p->get_color_string().c_str()));
}
