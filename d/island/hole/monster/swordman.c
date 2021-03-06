#include <../hole.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(19);
	set_name( "Lizardman swordman Abon","亚邦" );
	add( "id",({ "lizardman","swordman","abon" }) );
	set_short( "蜥蜴人剑术师 亚邦" );
	set_long(@LONG
    你看到的是一位气宇非凡的剑客，他现在主要以训练年青人为主
。听说它年青时曾经单身闯入龙穴，与人间凶兽『火麒麟』大战三天
三夜。由於火麒麟身上的鳞片非常坚硬，加上火麒麟身上奇热无比，
无法接近，所以始终不分上下。後来它发现火麒麟身上有一个地方的
鳞片脱落，於是朝这缺口奋力一击，终於将火麒麟杀死。它觉得这麒
麟的鳞片非常怪异，於是顺手将火麒麟的皮剥下。後来它将这张兽皮
拿给当时最有名的工匠『爱吉斯』研究，『爱吉斯』就用上面的鳞片
替它打造了『火麟战甲』、『火麟护臂』、『火麟盾』和『火麟剑』。
LONG
		);
	set( "gender","male" );
	set( "race","lizardman" );
	set( "alignment",-800 );
	set( "time_to_heal",6 );
	set_natural_armor( 55,35 );
	set_natural_weapon( 35,10,15 );
	set( "max_hp",950 );
	set( "hit_points",950 );
	set_perm_stat( "str",30 );
	set_perm_stat( "dex",25 );
	set_perm_stat( "kar",25 );
	set_perm_stat( "int",20 );
	set_skill( "parry",100 );
	set_skill( "block",100 );
	set_skill( "tactic",100 );
	set_skill( "shortblade",100 );
	set_skill( "dodge",80 );
	set( "tactic","assault" );
	set( "wealth/gold",150 );
	set( "special_defense",([ "none":20,"fire":80 ]) );
	set( "aim_difficulty",
	([ "weakest":70,"critical":70,"vascular":45,"ganglion":80 ]) );
	set( "stun_difficulty",80 );
	wield_weapon( HWEAPON"scale_sword" );
	equip_armor( HARMOR"arms5" );
	equip_armor( HARMOR"plate3" );
	equip_armor( HARMOR"shield7" );
}
