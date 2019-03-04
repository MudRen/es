#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "Teacher ziba", "������ʦ ������" );
	add( "id", ({ "teacher","ziba" }) );
	set_short( "Teacher ziba", "������ʦ ������" );
	set_long(@QQQ
����ǰ��һ�����ͷ���ͷ��������,��������һֻ����һ��,���㻳����������
������ܵ�������ʦ
QQQ
 );
	set( "unit", "λ" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 15 );
        set_perm_stat( "dex", 16 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 20 );    
        set( "max_hp",700 );
        set( "hit_points",700 );
 	set_natural_armor( 55,25 );
	set( "natural_weapon_class1", 25 );
	set( "natural_min_damage1", 11 );
	set( "natural_max_damage1", 24 );
	set( "natural_weapon_class2", 20 );
	set( "natural_min_damage2", 10 );
	set( "natural_max_damage2", 18 ); 
        set( "special_defense",([ "all":10,"none":25 ])); 
        set( "aim_difficulty",([ "critical":85,"weakest":30,"ganglion":50,
                                 "vascular":35 ]));
        set( "stun_difficulty",5);  
	set( "alignment", 2000 );
	set_c_limbs( ({ "ͷ��", "����", "����", "�ʺ�", "����"  }) );
        set_skill( "parry",80 );
        set_skill( "longblade",100 );
        set_skill( "two-weapon",100 );
        set_skill( "tactic",100 );
        set( "tactic","berserk" );
        set( "wealth" , ([ "gold": 110 ]) );
        set( "chat_chance",15);
        set( "att_chat_output", ({@AAA
�����ʹ�ȵ����������ı�������Ȼ��������ʦ��ս������
AAA
,@BBB
������˵��С�����ٲ����ҿɾͲ������ˣ�������
BBB
             }) );
        wield_weapon2(MOBJ"fish_sword.c");    
        wield_weapon(MOBJ"bird_sword.c");
        equip_armor(MOBJ"fencing_cloth.c");
        equip_armor(MOBJ"white_headband.c"); 
}
