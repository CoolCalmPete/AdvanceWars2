#ifndef AW_GAME_CONTROLLER_H
#define AW_GAME_CONTROLLER_H

#include "game.h"

#include "game_mechanics/traverse.h"
#include "game_mechanics/path.h"
#include "scene.h"
#include "units/actions.h"

#include <list>

#include <boost/signals.hpp>
#include <boost/utility.hpp>

/*
Bewegen
Nach einem Klick auf eine Einheit wird game::begin_unit_move() ausgef�hrt.
Bei Mausbewegung wird der Path neu berechnet.
Abbruch
Wird die Bewegung abgebrochen, wird game::cancel_unit_move() ausgef�hrt.

Aktionen
M�gliche Aktionen werden in game_controller errechnet und angezeigt

Angriff
Nachdem Angriff ausgew�hlt wurde, werden die M�glichkeiten errechnet.
Nach der best�tigung wird complete_unit_move()  und game::attack_unit() ausgef�hrt.

Explodieren
gamestate wird zu attacking.
Explosionsreichweite wird angezeigt und nach Konfirmation wird complete_unit_move() und explode() aufgerufen.

�bernehmen
complete_unit_move() und capture_building() werden aufgerufen

Einladen
game::load_unit() wird aufgerufen (ruft complete_unit_move() auf)

Ausladen:
Beim ausladen wird erst das Men� angezeigt, Nach der Auswahl einer Einheit werden die m�glichen Ausladefelder angezeigt.
Wird vor dem ersten Ausladen abgebrochen, wird cancel_unit_move() aufgerufen.
Beim ausladen wird game::unload_unit(from, to) aufgerufen (berechnet Sprit usw.)
Nachdem die erste Einheit ausgeladen wurde, wird complete_unit_move() ausgef�hrt.

Hide
game::hide_unit() wird aufgerufen

Appear
game::appear_unit() wird aufgerufen

Cancel
game::cancel_unit_move() wird aufgerufen

Raketensilo
gamestate wird zu attacking und es wird der Zielort ausgew�hlt. Danach wird game::launch_silo() ausgef�hrt
Bei abbruch wird das auswh�hlen des Zielpunktes abgebrochen und das Men� gezeigt.
Eventuell wird die Einheit auch nur zur�ck ins Bewegen versetzt, je nach komplexit�t


Anzeige
Die Szene wird von der map angenommen, wird von game eventuell ver�ndert, und schlie�lich in game_controller vervollst�ndigt.

Vielleicht sollte die komplette Szene erst in game_controller erzeugt werden.
Map erzeugt und game verarbeitet dann nur ein Zwischenobjekt, was nur die Map beinhaltet,

Vielleicht sollte scene umgebaut werden, so dass sie eine liste mit pair<string, area> enth�lt.
*/

/*
//NOTE: Ideas for signals:

signal_unit_clicked()
signal_terrain_clicked()
*/

namespace aw
{
	//NOTE: Eventuell einen neuen State "SELECTING" einf�hren und die im Men� ausgew�hlte Aktion in einer Variable speichern
	class game_controller
	{
		public:
			typedef boost::shared_ptr<game_controller> ptr;
			
			typedef boost::signal<void (const scene::ptr&)> scene_changed_t;
			
			//Menu-Callbacks
			typedef boost::signal<units::actions (const std::list<units::actions>&)> unit_action_menu_callback_t;
			typedef boost::signal<unit::types (unit::workshops, const player::ptr&)> unit_buy_menu_callback_t;
			typedef boost::signal<int (const std::list<unit::ptr> &)> unit_unload_menu_callback_t;

			enum gamestate { IDLE, DISPLAYING, MOVING, ATTACKING, UNLOADING, REPAIRING };

			game_controller();
			void start_game(const game::ptr &game);
			void start_turn();
			void end_turn();

			void click(const coord &pos, int key);
			void mouse_hover_changed(const coord &pos);

			scene_changed_t &signal_scene_change() { return m_signal_scene_changed; }
			
			//Callback access methods
			unit_action_menu_callback_t &signal_show_unit_action_menu() { return m_unit_action_menu_callback; }
			unit_buy_menu_callback_t &signal_show_buy_menu() { return m_unit_buy_menu_callback; }
			unit_unload_menu_callback_t &signal_show_unload_menu() { return m_unit_unload_menu_callback; }
			
		private:
			void on_unit_click(const coord &pos, int key);
			void on_building_click(const coord &pos, int key);
			void on_free_click(const coord &pos, int key);

			units::actions show_actions(const coord &pos);
			void process_action(units::actions action, const coord &pos);

			scene_changed_t m_signal_scene_changed;
			void update_display();

			gamestate m_gamestate;
			coord m_selection;
			std::size_t m_unload_index;

			game_mechanics::traverse::ptr m_traverse;
			game_mechanics::path::ptr m_path;
			area m_highlighted_area;

			game::ptr m_game;
			
			unit_action_menu_callback_t m_unit_action_menu_callback;
			unit_buy_menu_callback_t m_unit_buy_menu_callback;
			unit_unload_menu_callback_t m_unit_unload_menu_callback;
	};
}

#endif // AW_GAME_CONTROLLER_H
