#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "samurai wei","��ʿ ��" );
	add( "id", ({ "samurai","wei" }) );
	set_short( "��ʿ ��" );
	set_long(@AAA
����һ����ͺ������ʿ,��Ȼ�������,������������Խ������ر������
�ĸо�,����������ʿ��������һ����ٮٮ����,�Ǵ��ڶӳ���������ѡ!!
AAA
          );
	set( "unit", "λ" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 22 );
        set_perm_stat( "kar", 15 );
        set_perm_stat( "pie", 13 );    
        set( "max_hp",450 );
        set( "hit_points",450 );
 	set_natural_armor( 60,35 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 35 ); 
        set( "special_defense",([ "all":25,"none":15 ])); 
        set( "aim_difficulty",([ "critical":90,"weakest":30,"ganglion":40,
                                 "vascular":5 ]));
        set( "stun_difficulty/ma",5);  
	set( "alignment", -100 );
	set_c_limbs( ({ "ͷ��", "����", "����", "�ʺ�" }) );
        set_skill( "parry",100 );
        set_skill( "longblade",70 );
        set_skill( "tactic",100);
        set("tacitc","berserk");
        set( "wealth" , ([ "gold": 30 ]) );
        set( "weight", 400 );    
        wield_weapon(MOBJ"dragonscale_sword.c");
        equip_armor(MOBJ"samurai_boots.c");
        equip_armor(MOBJ"samurai_leggings");
        equip_armor(MOBJ"heart_necklace.c");
         
}
