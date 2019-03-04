#include <mudlib.h>

inherit TEACHER;
inherit MONSTER ;

void create ()
{
	::create();
	set_level(19);
	set_name( "Dalifore", "������" );
	add ("id", ({ "captain", "knight", "dalifore" }) );
	set_short( "������ʿ�� ������ ����");
	set_long(@CLONG
��������ŵ����ʿ���н������˼�ų��ĵڶ���������ó��������ǳ�
�࣬��˹�����������ѵ���ʼ���ʿ�ǵ��������ɡ�
CLONG
	);
	set_perm_stat("str", 30 );
	set_perm_stat("con", 25 );
   set_skill( "tactic", 100 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "block", 100 );
	set( "alignment", 1500 );

	set( "race", "human" );
	set( "gender", "male" );

	set( "hit_points", 800 );
	set( "max_hp", 800 );

	set_natural_weapon( 15, 5, 20 );
	set_natural_armor( 70, 30 );
	
   set( "tactic", "flank" );
   set("special_defense",(["all":30]));
    set("aim_difficulty",([ 
    	"critical":80,"vascular":50,"weakest":50,"ganglion":50 ]) );
	
	wield_weapon( "/d/noden/nodania/obj/markara" );
	equip_armor( "/d/noden/nodania/obj/steel_plate" );
	equip_armor( "/d/noden/nodania/obj/steel_leggings" );
	equip_armor( "/d/noden/nodania/obj/steel_gauntlets" );
	equip_armor( "/d/noden/nodania/obj/shield" );
	equip_armor( "/d/noden/nodania/obj/steel_boots" );
	equip_armor( "/d/noden/nodania/obj/steel_helmet" );
	set( "inquiry", ([
		"lucksis" : "@@ask_lucksis",
		"yamor" : ({
			"��Ĭ��.... û�����Ǵ�Ӧ��Ҫѵ��(train)���Ĺ����Ա ....��\n" }),
		"train" : ({
"�ҿ��Խ��㳤��������(longblade)��ս������(tactic)�ļ��ɡ�\n" }),
	        "tactic" : ({
			"����!?�������ҾͲ�����!\n" }),
		"longblade" : ({
			"û�������������ҾͲ����ˣ�\n" })
	]) );
	set_lessons( ([
	   "tactic" : ({ 200, 45 }),
           "longblade" : ({ 150, 55 })
	]) );
}

void ask_lucksis(object who)
{
     if ( !(who->query_temp("lucksis_quest")) || 
     	  !(who->query_temp("lucksis_quest/ask")) ) 
       tell_object(who,"������˵��: �Բ���,������ѵ��ʿ��.\n");
     else {
         tell_object(who,
         	"������˵��: ��������ϣ˿������?\n"
            "����һ��������, ��ʱ���������﹥��, ���Ҿ�������\n"
            "�����������Ĺ���, ֻ�������������˲�ͬ����..\n"
            "�����Ҿ�������, ԭ��������˵, ����ʵ�������,\n"
            "Ϊ���һ��ر����������, ����ǰ��ңԶ��������ء�\n"
            "�밫����Ī���»�����˫�ߵ��⽻�������Ҳ��ӹ���\n"
            "�ľ�����\n������˵����,����ѵ��ʿ����\n\n\n"
            "����ô�����������ϣ˿�Ĺ�ϵ�ƺ����仨����, ����ˮ���顣\n"
         );
         who->set_temp("lucksis_quest/dalifore",1);             
     }
}

void init()
{
   teacher::init();
   npc::init();
}

int check_trainee(object trainee)
{
	if( (string)trainee->query("class")!="adventurer"
	|| (int)trainee->query_level()<5 ) {
		return notify_fail(
		"������ҡҡͷ��˵��: ���ݵ�������Ĭ��Լ������ֻ�� 5 �����ϵ�ð���ߡ�\n"
	); 
      }
	return 1;
}
