#include "/d/mage/tower/detect-magic.h"

inherit MONSTER;
string magictype;
void create()
{
	object obj;
	::create();
	set_level(19);
	set_name( "patolas", "������˹" );
	set_short( "ħ��ʦ  ������˹" );
	set_long(	"    ħ��ʦ������˹��ħ�������ţ���춼������ߵ�ħ���������Լ��������ֵ�\n"
"ħ�����������к�����о��������ڰ���һ�������ˮ����(orb)��\n"
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", -300 );
	set( "time_to_heal", 8 );
	set("max_hp",650);
	set("hit_points",650);
	set("max_sp", 2700);
	set("spell_points", 2700);
	set_natural_armor( 50, 20 );
	set_natural_weapon( 25 , 20 , 30 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "con", 15 ); 
	set_perm_stat( "kar", 23 );
	set_perm_stat( "int", 30 );

	set("special_defense", ([ "all" : 5, "none" : 40, ]) );
	set("aim_difficulty",(["critical":30,"weakest":30,
                               "vascular":30,"ganglion":30 ])) ;
	set_skill("elemental",100);
	set_skill("misc",100);
	set_skill("black-magic",100);
	set_skill("magic-shield",100);
	set_skill("concentrate",100);
	set_skill("target", 100);
	set_skill("dodge",80)    ;
	set_skill("unarmed",100) ;
	set( "wealth/gold", 100 );
	set("magic_delay", 1);
	set("spells/fireball",4);
	set("spells/sleet",2);
	set("spells/lightning",2);
	set("spells/flare",1);
	set("spells/ether-bolt",5);
	set("spells/ice-shield",4);
	set("spells/flamming-shield",4);
	set("spells/energy-shield",4);
	set("spells/mirror-shield",4);
	set("spells/heart-protect-shield",4);
	set("spells/magical-shield",4);
	obj=new("/d/mage/tower/obj/crystal_orb.c");
	obj->move(this_object());
	equip_armor( "d/noden/moyada/obj/magic_robe" );
	wield_weapon("/d/noden/nodania/obj/ivory_dagger.c");
	set( "inquiry" , ([ "identify":"@@identifying","orb":"@@ask_orb",]) ) ;
	set( "tactic_func", "cast_spell" );
}

void identifying(object who)
{
  tell_object(who,"������˹˵:��Ҫ����ˮ�������������ߵ�ħ�������������������������롣\n") ;
}

void ask_orb(object who)
{
  tell_object(who,"������˹˵:˵�����ˮ�������ˮ���������֮������ܼ������ߵ�ħ��������\n������˹����˵���������߸���Ѱ�Ҳ��ϣ���ʩ������ħ��������ɣ�����������Ʒ��\n") ;
}

int receive_special_damage(string type, int damage)
{
	magictype=type;
	::receive_special_damage(type,damage);
}

int cast_spell()
{
    object victim,me;
    string magicname;
    int i,min_defense,temp;
    me=this_object();
    if ( !me->query_temp("effect/magical-shield") ){
	command("cast magical-shield");
	return 1;
	}
	switch (magictype) {
		case "fire":  if (!me->query_temp("effect/ice-shield") ) 
				{command("cast ice-shield");	return 1;}
				break;
		case "cold":  if (!me->query_temp("effect/flamming-shield") ) 
				{command("cast flamming-shield");	return 1;}
				break;
		case "electric":  if (!me->query_temp("effect/mirror-shield") ) 
				{command("cast mirror-shield");	return 1;}
				break;
		case "energy":  if (!me->query_temp("effect/energy-shield") ) 
				{command("cast energy-shield");	return 1;}
				break;
		case "evil":  if (!me->query_temp("effect/heart-protect-shield") ) 
				{command("cast heart-protect-shield");	return 1;}
				break;
	}

    victim = query_attacker();
    if( !victim ) return 0;
    if( random(10)>7 ) return 0;
    min_defense=victim->query_special_defense("fire");
    magicname="fireball";
    temp=victim->query_special_defense("cold");
    if (min_defense > temp) {
	min_defense=temp;
	magicname="sleet";
    }
    temp=victim->query_special_defense("electric");
    if (min_defense > temp) {
	min_defense=temp;
	magicname="lightning";
    }
    temp=victim->query_special_defense("energy");
    if (min_defense > temp) {
	min_defense=temp;
	magicname="ether-bolt";
    }
    temp=victim->query("defense_bonus");
    if (( temp < 30) && (random(3)<1)) {
	magicname="flare";
    }

    command( "cast "+magicname+ " on "+victim->query("name"));
    return 1;
}
