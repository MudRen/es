#include <mudlib.h>

inherit TEACHER;
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "captain", "�����ӳ�" );
	add( "id", ({ "guard" }) );
   set_short( "�����ӳ�" );
   set_long( @LONG
��λ�����ӳ�����������ǰ��һЩ���ģ�������ʱ����һλΰ���ð��
�ߣ����ڴӺ������ݣ�������ɳ�۵ľ����������������Ϊ�˴�������
(pirate)���ֵ��¶���ͷ�ö
LONG
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 27 );
   set_perm_stat( "dex", 22 );
   set_perm_stat( "kar", 24 );
   set( "max_hp", 1200 );
   set( "hit_points", 1200 );
	set_skill( "longblade", 100 );
	set_skill( "shortblade", 100 );
	set_skill( "two-weapon", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set_skill( "tactic", 100 );
	set( "tactic", "berserk" );
   set( "tactic_func", "call_help" );
	set( "wealth/gold", 180 );
   set( "weight", 850 );
   set( "special_defense", ([ "fire":50, "cold":50, "none":-5 ]) );
	set( "alignment", 1400 );
   set_natural_armor( 50, 10 );
   set( "aim_difficulty", ([
   "critical":30, "ganglion":30, "weakest":30,"vascular":30 ]) );
   set_natural_weapon( 17, 15, 25 );
   set_natural_weapon2( 15, 10, 20 );
   wield_weapon2( "/d/noden/bluesand/item/etheral_cutlass" );
   wield_weapon( "/d/noden/bluesand/item/murasame" );
   set_lessons( ([
                  "parry" : ({ 200, 50 })
   ]) );
   set( "inquiry", ([
     "parry" : "���������м���! Ҫѧ�Ϳ졣\n",
     "pirate" : "����������, �����Ѻ���ͷ�ӵ��Դ�����, �һ����һЩ������\n"
   ]) );
}

void init()
{
   teacher::init();
   npc::init();
}

int accept_item(object who, object item)
{
   if( (string)item->query("c_name")=="��˹������ͷ" )
   tell_object( who,
        "�ܺ�! ����ͷ���������!\n"
        "���Ǹ���Ľ���������ѧ�����м�(parry)��?\n" );
   who->set_temp("train_parry", 1);
   who->credit("gold", 50);
   item->remove();
   return 1;
}

int check_trainee(object who)
{
   if( !who->query_temp("train_parry") )
   return notify_fail(
        "�ر��ӳ�˵��: ���Ƚ�����˹������ͷ��\n" );
   if( (string)who->query("class")=="adventurer"
     && (int)who->query_level()> 4 )
   return 1;
   else return notify_fail(
        "�ر��ӳ�˵��: ��ֻ�̹��ʸ��ð���ߣ�����������ϣ�\n" );
}

int call_help()
{
   object cop1, cop2, cop3, victim;
   int hp;

   victim = query_attacker();
   hp = this_object()->query("hit_points");

   if( hp>250 ) return 0;
   if( random(10)> 3 ) return 0;
   if( present("cop", environment(this_object())) ) return 0;
   tell_room( environment(this_object()),
      "������Ա�Ǵ�е�: ˭�Ҷ��ӳ�!?�����µ���!!\n\n" );
   cop1 = new("/d/noden/bluesand/monster/cop");
   cop2 = new("/d/noden/bluesand/monster/cop");
   cop3 = new("/d/noden/bluesand/monster/cop");
   cop1->move(environment(this_object()));
   cop2->move(environment(this_object()));
   cop3->move(environment(this_object()));
   cop1->kill_ob(victim);
   cop2->kill_ob(victim);
   cop3->kill_ob(victim);
   return 1;
}

void die()
{
   object *blade, murasame;

   blade = children( "/d/noden/bluesand/item/murasame" );
   murasame = present( "murasame", this_object() );
   if( sizeof(blade) > 1 ) {
        tell_room( environment(this_object()),
		"�����ӳ�ŭ��: ��! ��������ܱ�ë��ɱ������ʹ��������Ҳ�����õ�����!\n"
		"�����ӳ��þ�����������Ѵ���������ɳ����!\n",
		this_object() );
        murasame->remove();
   }
   ::die();
}