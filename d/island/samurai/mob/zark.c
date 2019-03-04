#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "samurai Zark","��ʿ ����" );
	add( "id", ({ "samurai","zark" }) );
	set_short( "��ʿ ����" );
	set_long(@AAA
������һ���о����������ĸ���,�����Դ����õ���ħ��(����֮��)��,������
��춽����ϵ��о�,�����ڿ��������ϵ��ٶ�,�ڼ���ħ��������,���Ӯ����
����һ�����׵�����
AAA
   );
	set( "unit", "λ" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 15 );    
        set( "max_hp",1000 );
        set( "hit_points",1000 );
 	set_natural_armor( 85,25 );
	set( "natural_weapon_class1", 20 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 40 ); 
        set( "special_defense",([ "all":5,"none":5 ])); 
        set( "aim_difficulty",([ "critical":50,"weakest":20,"ganglion":50,
                                 "vascular":15 ]));
        set( "stun_difficulty/ma",7);  
	set( "alignment", -1000 );
	set_c_limbs( ({ "ͷ��", "����", "����", "�ʺ�" }) );
	set_c_verbs( ({ "%s�����ֵ���%s���ʺ�����һ��", "%s����ֱȭ��%s��С������" }) );
        set_skill( "parry",70 );
        set_skill( "shortblade",100 );
        set_skill( "unarmed",100 );
        set_skill("tactic",100);
        set("tactic","melee");
        set( "wealth" , ([ "gold": 100 ]) );
        set( "forgetful", 1);    
        wield_weapon(MOBJ"sound.c");
        equip_armor(MOBJ"karate.c"); 
}
