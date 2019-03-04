#include <../hole.h>        
        
inherit MONSTER;
void create ()
{
	::create();
	set_level(15);
	set_name( "Flesheater Fish","食人鱼" );
	set ( "id",({ "fish" }) );
	set_short( "食人鱼" );
	set_long(@LONG
这是一条凶悍的食人鱼，正在这儿觅食。
LONG
		);
	set( "likefish",1 ) ;
	set( "unit","条" );
	set( "alignment",-1000 );
	set( "killer",1 );
	set( "moving",1 );
	set( "speed",30 );
	set_natural_weapon( 60,15,40 );
	set_skill( "unarmed",80 );
	set_natural_armor( 40,10 );
	set( "c_killer_msg",
	"食人鱼看到你那『白晰晰、幼咪咪』的肌肤，色眯眯地在你身旁徘徊\n\n" );
	set_c_verbs( ({ "%s用利刃般的背鳍刺向%s","%s张开长满利牙的大嘴咬向%s" }) );
	set_c_limbs( ({ "鱼鳍","尾巴","头部" }) );
	setenv( "C_MIN","$N迅速地游了过来" );
	setenv( "C_MOUT","$N缓缓地向$D游了过去" );
}