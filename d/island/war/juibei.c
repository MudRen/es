#include "../island.h"

inherit IWAR"i_warvalue";

void create()
{
	::create();
	set_level(19);
	set_name( "Samurai Juibei","ʮ����" );
	add( "id", ({ "samurai","juibei" }) );
	set_short( "��ʿ�ر��ӳ� ʮ����" );
	set_long(@AAA
ʮ��������ʿ�߾��ر��ӵĶӳ���������������˼�ħ����ӵĶ���
AAA
);
	set( "unit", "λ" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "justice", 15 );
	set_perm_stat( "str", 27 );
	set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 20 );    
        set( "max_hp",650 );
        set( "hit_points",650 );
 	set_natural_armor( 48,10 );
	set( "natural_weapon_class1", 15 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 20 ); 
	set( "natural_weapon_class2", 5 );
	set( "natural_min_damage2", 6 );
	set( "natural_max_damage2", 12 );
        set( "special_defense",([ "all":30,"none":30 ])); 
        set( "aim_difficulty",([ "critical":20,"weakest":20,"ganglion":50,
                                 "vascular":15 ]));
        set( "stun_difficulty",15);  
	set( "alignment", -2000 );
	set( "killer", 1);
        set_skill( "parry",100 );
        set_skill( "two-weapon",100);
        set_skill( "longblade",100 );
        set_skill( "tactic",100);
        set("tacitc","berserk");
        set( "wealth" , ([ "gold": 250 ]) );
        wield_weapon(IWARO"moon_sword.c");
        wield_weapon2(IWARO"star_sword.c");
        equip_armor( IWARO"samurai_cloak.c");
        equip_armor( IWARO"samurai_cloth.c");
        equip_armor( IWARO"samurai_mark.c");
        equip_armor( IWARO"samurai_armband.c");
        set("chat_chance", 20 );
        set("att_chat_output", ({
        "ʮ������ȵ���������ЩΥ����Լ��ƭ�ӣ���Ҫ�׹����ǣ�����\n",
        "ʮ����˵�����ֵ��ǣ�����ɱ�����ǣ���Ҫ�����ǿ�����������\n",
        "ʮ����˵����������ʿ�Ŵ����Ҫ���ˣ�����һ������ڵģ���\n"
        }));
             
}
