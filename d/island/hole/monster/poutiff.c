#include <../hole.h>

inherit MONSTER;
void create ()
{
	::create();
	set_level(17);
	set_name( "Lizardman Poutiff Rasoda","������" );
	add( "id",({ "poutiff","rasoda" }) );
	set_short( "�����˼�˾ ������" );
	set_long(@LONG
    �㿴������һλ���������˴���ļ�˾������������������̽�
�ͣ��޷���Ϊʩ���ߣ��������䡺����ϣ�ࡻ�м�춷�����ս���ϵ�
��Ҫ�ԣ�����ص���Ī�Ǵ�ǽ����������������������ƺ���ʲ����
������������
LONG
		);
	set( "alignment",600 );
	set( "exp_reward",28000 );
	set( "gender","female" );
	set( "race","drow");
	set( "unit","��" );
	set_perm_stat( "dex",21 );
	set_perm_stat( "str",11 );
	set_perm_stat( "int",25 );
	set_perm_stat( "pie",20 );
	set_perm_stat( "kar",22 );
	set( "max_hp",450 );
	set( "max_sp",1800 );
	set( "hit_points",450 );
	set( "spell_points",1800 );
	set( "wealth",([ "gold":25 ]) );
	set_natural_weapon( 16,12,17 );
	set_natural_armor( 45,24 );
	set( "weight",300 );
	set_skill( "target",100 );
	set_skill( "elemental",100 );
	set_skill( "black-magic",100 );
	set( "guild_levels/black-magic",70 );
	set( "guild_levels/elemental",70 );
	set( "guild_levels/guild",70 );
	set_skill( "concentrate",100 );
	set_skill( "dodge",90 );
	set_skill( "whip",100 );
	set( "magic_delay",2 );
	set( "spells/flare",1 );
	set( "spells/sleet",4 );
	set( "spells/fireball",5 );
	set( "special_defense",([ "all":35,"none":10 ]) ); 
	set( "aim_difficulty",([ "vascular":20 ]) );
	set( "tactic_func","cast_spell" );
	wield_weapon( HWEAPON"chabok" );
	equip_armor( HARMOR"cloth1" );
	equip_armor( HARMOR"cloak4" );
	equip_armor( HARMOR"ring1" );
	equip_armor( HARMOR"amulet4" );
	equip_armor( HARMOR"helmet7" );
	set( "inquiry",([ "vampire" : "@@ask_vampire",
//	                  "charge" : "@@ask_charge" 
	                  ]) );
}

void init()
{
	::init(); 
	add_action( "to_report","report" ); 
}

int cast_spell()
{
	object victim;
	string name;
	
	if( !(victim = query_attacker()) ) return 0;
	
	name = victim->query( "name" );
	if( random(20) < 5 ) {
	command( "cast flare on "+name );
	return 1;
	}
	
	if ( random(20)< 4 ) {
	command( "cast fireball on "+name );
	return 1;
	}
	
	else if ( random(20)< 3 ) {
	command( "cast sleet on "+name );
	return 1;
	}
	else return 0;   
}

int to_report(string arg)
{
	string what,man;
	
	if( !arg || sscanf(arg,"%s to %s",what,man)!=2 )
	return notify_fail( "������˵�������ţ���ʲ�����𣿡�\n" );
	
	if( man!="rasoda" && man!="poutiff" )
	return notify_fail( "����û������ˡ�\n" );

	else
	{
	switch(what){
		case "kirs" :
		write(@ALONG
�����￴�������е�Сľ��˵:
�š���ľ���ɵĶ̵���������ҵ���ȥ��Ѫ�����������
�������������ǲ����ģ���Ѫ��ĵ��и�����ҵ�����
��Ϣ�ز���һ�����׵��£������ҵ�������Ϣ�أ�����Ҳ
����������������������ҵ���ˮ����Ψ��������ˮ����
ħ��������Ѫ���������д�����Ŀ��ܡ�����ľ�̵���
�ң����Ƚ�������������ľ�̵��ϰɡ�
ALONG
	);
		return 1;
		break;
		
		case "amethyst" :
		write(@BLONG
������������ļ��˵:
Ҫ����ˮ�����Ƕ������и�ˮ���������㿴���ѳ�ˮ��ȥ
֮�ᣬ�ܲ����ҵ���������ˮ���ɣ�
BLONG
	);
		return 1;
		break;
	default :
		return notify_fail( "���������һ��������˵������ر�һЩ�޹ؽ�Ҫ�����顣��\n" );
	}
	}
}

int accept_item(object me,object item)
{
	string *name;
	
	name=item->query( "id" );
	if ( name[0]=="mahogany kirs" ){
	tell_room( environment(me),
	"������������������е���ľ�̵�����һ������Ĺ�â��\n" );
	tell_object( me,"������˵:���Ѿ�����ľ�̵�ʩ��ħ���ˣ����ȥ�������Ķ����ɣ�\n" );
	item->set( "charge",1 );
	command( "give kirs to "+lower_case( (string)me->query("name") ) );
	return 1;
	}
	else
	return notify_fail( "������˵��: �����һ����������\n" );
}

void ask_vampire()
{
        if( this_player()->query_temp("lizard_quest/poutiff") )
        {
          tell_object( this_player(),@ALONG
������˵: Ŷ���ǹ�������Ҫ����������Ѫ��ȷʵΣ�����Ǿ���İ�ȫ�ܾ��ˣ�
��������������Ҳ֪���ǵ�����ľ����������������������һ����ľ(mahogany)��
          �󣬶�����ʵ����̫�������ˣ�����һֱ�޷����������ټ�����......
ALONG
          );
          this_player()->delete_temp("lizard_quest/poutiff");
          this_player()->set_temp("lizard_quest/feller",1);
          return;
        }
        write("������ҡҡͷ˵: �Һ�æ�����ң�\n");
        return;
}
