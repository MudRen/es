
#include "../goomay.h"

inherit TEACHER;
inherit MONSTER;

void create ()
{
	object ob1,ob2;
        ::create();
        set_level(17);
	set("alignment",250);
	set("class","adventurer");
        set_name( "travelling fighter", "�����䶷��" );
	add ("id", ({ "fighter" }) );
        set_short("�����䶷��");
        set("unit","��");
        set_long(
@C_LONG
����һλ���ݵ������䶷�мң�ѩ�׵�ͷ���͸�ǿ�����Ӷ��̻�����
�����о��飬���ƺ�����ֻ��һ�����������ˣ���������û�д���һ
�������߰��õ����ȣ�����һ����ֵ���צ������ϸ��������������
צ������ող��õ���һ����
C_LONG
);
        set ("gender", "male");
        set ("race", "human");
        set_natural_armor( 70, 20 );
        set_natural_weapon( -5, -6, 4 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 30 );
        set_skill( "unarmed", 100 );
        set_skill( "parry", 100 );
        set( "hit_points", 500 );
        set( "max_hp", 500 );
        set( "special_defense", ([ "all": 20 ]) );
        set ("wealth", ([ "silver": 200 ]) );
        set( "tactic_func", "my_tactic" );
        set("no_steal",1);
        ob1 = new( Obj"claws" );
        ob1->move( this_object() );
        ob2 = new( Obj"travel_bag" );
        ob2->move( this_object() );

        equip_armor( Obj"fighter_robe" );
    set( "inquiry", ([
         "unarmed" : "@@ask_unarmed",
         ]) );
    set_lessons(([
       "unarmed": ( { 250,85 } )
       ]) );

}
void ask_unarmed(object who)
{

     if ( (int)who->query_quest_level("Goddess_statue") < 2)
        {
          tell_object(who,"�䶷��˵���������Ȱ��ҵ����ѽ�����ķ��հ� !!\n");
          return ;
	}
     else
       {
        tell_object(who,"�ҵĿ��ֲ���������һ�����������ҽ̵�,��Ҫѧϰ��\n");
        return ;
       }
}

void init()
{
	teacher::init();
	npc::init();
}

int my_tactic(string arg)
{
	if ( query("weapon_class1") > 50 ) return 0;

	tell_room(environment(),
		"���мҴ�Ц�� �� ������ !! ���ú� !! ������������צ !!��\n" );
	command("wield iron claws");
	set("hit_points",500);
	delete("tactic_func");
        return 1;
}

void die()
{
	command("unwield claws");
	::die();
}

int check_trainee(object who)
{
    if ((string)who->query("class")=="adventurer" && 
	(int)who->query_quest_level("Goddess_statue")> 1)
      return 1;
    else 
      { tell_object(who,"�䶷��˵���������Ȱ��ҵ����ѽ�����ķ��հ� !!\n");
        return 0 ;
        }
}



