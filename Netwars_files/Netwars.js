// Created by iWeb 2.0.4 local-build-20090627

setTransparentGifURL('Media/transparent.gif');function applyEffects()
{var registry=IWCreateEffectRegistry();registry.registerEffects({reflection_0:new IWReflection({opacity:0.60,offset:1.00})});registry.applyEffects();}
function hostedOnDM()
{return false;}
function onPageLoad()
{loadMozillaCSS('Netwars_files/NetwarsMoz.css')
adjustLineHeightIfTooBig('id1');adjustFontSizeIfTooBig('id1');adjustLineHeightIfTooBig('id2');adjustFontSizeIfTooBig('id2');adjustLineHeightIfTooBig('id3');adjustFontSizeIfTooBig('id3');adjustLineHeightIfTooBig('id4');adjustFontSizeIfTooBig('id4');adjustLineHeightIfTooBig('id5');adjustFontSizeIfTooBig('id5');Widget.onload();fixAllIEPNGs('Media/transparent.gif');IMpreload('Netwars_files','shapeimage_3','0');IMpreload('Netwars_files','shapeimage_3','1');IMpreload('Netwars_files','shapeimage_3','2');IMpreload('Netwars_files','shapeimage_3','3');fixupIECSS3Opacity('id6');applyEffects()}
function onPageUnload()
{Widget.onunload();}