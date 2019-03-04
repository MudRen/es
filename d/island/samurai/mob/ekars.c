#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "samurai ekars","��ʿ ����˹" );
	add( "id", ({ "samurai","ekars" }) );
	set_short( "��ʿ ����˹" );
	set_long(@AAA
������ǰ��һλ��߽����������ߵľ޺�����춰���˹���������춳��ˣ���
�������õ�����Ҳ���˲�һ������ͬ�ƽ����ʿ������ʹ�����͵ı���������
Ϊ����������,���������������Ͼͺ���ͨ�˵����һ��
AAA
       );
	set( "unit", "λ" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 13 );
        set_perm_stat( "dex", 15 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 15 );    
        set( "max_hp",700 );
        set( "hit_points",700 );
 	set_natural_armor( 60,22 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 35 ); 
        set( "special_defense",([ "all":5,"none":15 ])); 
        set( "aim_difficulty",([ "critical":40,"weakest":10,"ganglion":5,
                                 "vascular":15 ]));
        set( "stun_difficulty/ma",13);  
	set( "alignment", 100 );
	set_c_limbs( ({ "ͷ��", "����", "����", "�ʺ�" }) );
        set_skill( "parry",40 );
        set_skill( "thrusting",100 );
        set_skill( "tactic",100 );
        set("tactic","berserk");
        set( "wealth" , ([ "silver": 400 ]) );    
        wield_weapon(MOBJ"cross_lance.c");
        equip_armor(MOBJ"black_vest.c");
        equip_armor(MOBJ"black_gauntlets.c");
        equip_armor(MOBJ"samurai_helm.c"); 
}
