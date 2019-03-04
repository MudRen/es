#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Ninja Kola","���� ����" );
	add( "id", ({ "ninja","kola" }) );
	set_short( "���� ����" );
	set_long(@AAA
���߸�������ʿ�źڰ������Ĵ������ɸ�������������߲����ڰ��ص��ж�����
����ʿ�ŵ�������ս���������ʿ�ŵı�ʤ����ʽ��������������������պų���
ʿ�Ǳ�����ǿ�ģ���������ŵĻ�����������һ�ԣ�����
AAA
        );
	set( "unit", "λ" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 18 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 15 );
        set( "time_to_heal",20 );    
        set( "max_hp",1000 );
        set( "hit_points",1000 );
 	set_natural_armor( 70,20 );
	set( "natural_weapon_class1", 20 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 40 ); 
        set( "special_defense",([ "all":25,"none":25 ])); 
        set( "aim_difficulty",([ "critical":90,"weakest":70,"ganglion":100,
                                 "vascular":35 ]));
        set( "stun_difficulty",10);  
	set( "alignment", -1000 );
	set_c_limbs( ({ "ͷ��", "����", "����", "�ʺ�" }) );
        set_skill( "parry", 80 );
        set_skill( "longblade", 100 );
        set_skill( "unarmed", 100 );
        set_skill( "dodge", 80 );
        set_skill( "tactic", 100 );
        set( "tactic","melee");
        set( "wealth" , ([ "gold": 100 ]) );
        set("chat_chance",15);
        set("att_chat_output",({@AAA
        
������Ц�����������ľ���ֵ�����𣿹����������Ҿͳ�ȫ��ɣ���

AAA
,@BBB

����˵�������Ǻܿ����ģ������������ȥԶ���������ëǮร���

BBB
}));    
        wield_weapon(MOBJ"evil_sword.c");
        equip_armor(MOBJ"dragon_chainmail.c");
        equip_armor(MOBJ"samurai_boots.c"); 
}
