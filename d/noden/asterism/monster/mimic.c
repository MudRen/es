#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "mimic", "���" );
	add("id",({"mimic"}) );
   set_short( "���" );
	set_long(
		"���Ƕ������ŵ����,��֪����������ֵ�����̽�ռҲ��ɼ�����.\n"
	);
	set("exp_reward",35000) ;
	set( "gender", "neuter" );
   set( "race", "undead" );
	set( "alignment", -1500 );
	set( "time_to_heal", 3 );
        set( "killer",1 ) ;
        set("max_hp",800);
        set("hit_points",800);
	set_natural_armor( 80, 33 );
	set_natural_weapon( 79 , 30 , 63 );
	set_perm_stat( "str", 27 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "con", 35 ); 
        set_perm_stat( "kar", 30 );
        set("aggressive",1) ;
        set("special_defense",(["all":40,"none":0]));
   set( "unbleeding", 1 );
        set("aim_difficulty",(["critical":100,"weakest":50,
                               "vascular":50,"ganglion":100 ])) ;

        set_c_verbs(({"%s������������%sײȥ","%s������������%sҧȥ"}));
        set_c_limbs(({"����","���"}));
        set_skill("dodge",65)    ;
        set_skill("unarmed",100) ;
	set( "wealth/gold", 600 );

}

