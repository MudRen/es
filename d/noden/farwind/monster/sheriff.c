// town_guard.c
// A pursuing monster. That is, if you are in combat with him, and
// you leave, he'll go after you. You can lose him if you run fast
// enough but otherwise he's pretty lethal.
// Also, if A attacks B, then the guard will attack A.
// Comments on monster properties are found in /obj/foobird.c
// Written by Mobydick, 6-20-93.

#include "/d/noden/farwind/farwind.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(15);
	set_name( "ebbruce", "����³˹" );
	add( "id", ({ "sheriff" }) );
	set_short( "Զ���򱣰��ٰ���³˹");
	set_long(@C_LONG
����³˹��������ϵı����٣������������ά��Զ����ĺ�ƽ������
�����ʮ�����࣬��ñ���Զ�����ܻ�ɻ��� (���ٱ�������ǰ����
����) ��
C_LONG
                );
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "natural_armor_class", 50 );
	set( "natural_weapon_class1", 10 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 10 );
	set( "max_hp", 450 );
	set( "hit_points", 450 );
	set( "moving", 1 );
	set( "speed", 30 );
	set( "patrol", ({ "north", "south", "west", "west", "east", "east",
		"south", "north" }) );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 18 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set( "special_defense", ([ "all": 20 ]) );

	wield_weapon( FARWIND"items/b_sword");
	equip_armor( FARWIND"items/leather_boots");
	equip_armor( FARWIND"items/breast_plate");

	set ("pursuing", 1) ;
	set ("inquiry", ([
"lucksis": "@@ask_lucksis"
	]) ) ;
}

void init()
{
   npc::init();
   add_action( "kill_killer", "kill" );
}

int kill_killer(string arg)
{
   object killer;

   killer = this_player();
   if( arg && present(arg,environment(this_object()))
        && arg != "ebbruce" && arg != "torch" )
   {
     if(killer) {
            kill_ob(killer);
            killer->kill_ob(this_object());
            tell_object(killer,
         "����³˹����һ�ۣ�˵��: �㾹�ҹ�Ȼ��Զ������Ұ��\n");
            tell_room(  environment(killer),
         "����³˹��üһ��,����һ��,���̳��ֺ���"+killer->query("c_name")+
        "......!\n", killer );
     }
   }
}

void ask_lucksis(object who)
{
     if (!(who->query_temp("lucksis_quest")) || (int)(who->query_temp("lucksis_quest/ask"))==0 ) 
       tell_object(who,"����³˹���ɲ�΢��Ц��վ��.\n"
                       );
     else
       {
         tell_object(who,"����³˹˵:��������ϣ˿������?\n"
                         "�Ǹ�СŮ�����ڻ���û�ж������Ϳ���?\n"
                         "����³˹¶���ѵ�һ����Ц��.Ȼ�����˵:\n"
                         "�Բ���,�ұ���ά����ط��İ�ȫ��,�������.\n"
                         "\n\n��о�������³˹�������ϣ˿�ƺ������κε�\n"
                         "����.������³˹������������κ��˲�������.\n"
                    );
         who->set_temp("lucksis_quest/ebbruce",1);             
       }
     return;
}

