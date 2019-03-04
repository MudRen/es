#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "a gnome magic student", "ħ��ѧͽ" );
	add("id",({"mage","gnome","student"}) );
   set_short( "ħ��ѧͽ" );
	set_long(
	"����ؾ�������ϰħ����������ʱ��͵�����,��ʱҪ��ͷ������ӡ������.\n"
        "��϶����ŸսӴ�ħ��û��á�\n"
	);
	set( "gender", "female" );
	set( "race", "gnome" );
	set( "alignment", 260 );
	set( "time_to_heal", 10 );
	set_natural_armor( 20, 9 );
	set_natural_weapon( 15 , 10 , 13 );
	set_perm_stat( "kar", 20 );
	set_perm_stat( "int", 20 );
	set("max_sp",600);
	set("spell_points",600);
	set_skill("concentrate",30);
	set_skill("target",30);
	set_skill("black-magic",40);
	set_skill("dodge",30);
	set_skill("dagger",80);
	set("spells",(["ether-bolt":2]));
	set( "wealth/gold", 10 );
//	wield_weapon(WEAPONS"sad_dagger");
//	equip_armor(ARMORS"cloak01");
	equip_armor(ARMORS"ring01");
        set( "tactic_func", "cast_help" ); 
}

int cast_help()
{ 
    object victim ;
    string name;
    int i;
    victim = query_attacker();
    
    if( !victim ) return 0; 

    if ( (int)this_object()->query("spell_points")< 300 )
       this_object()->set("spell_points",600);
    if ( random(10)<7 ) {
       name=victim->query("name");
       command("cast ether-bolt on "+name); 
       return 1;
       }
    else return 0;
}

