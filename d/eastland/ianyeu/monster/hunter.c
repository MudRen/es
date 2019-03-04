#include "../mad.h"

inherit TEACHER;
inherit MONSTER;

void create()
{
	::create();
   set_level(17);
   set_name( "hunter Jang", "���Ի�" );
   add( "id", ({ "jang", "hunter" }) );
   set_short( "���Ի�" );
	set_long(@C_LONG
�����������Ũü���ۣ�һ����ļ���ͽ�ʵ�ļ����ʾ�������ա�
�����û�µĻ�, ��������Զһ�㡣
C_LONG
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 800 );
   set_perm_stat( "str", 25 );
   set_perm_stat( "dex", 25 );
   set_perm_stat( "kar", 15 );
   set_skill( "longblade", 100 );
   set_skill( "parry", 100 );
   set_skill( "block", 100 );
	set_skill( "dodge", 60 );
   set_skill( "anatomlogy", 80 );
	set( "aiming_loc", "ganglion" );
   set( "hit_points", 600 );
   set( "max_hp", 600 );
	set( "wealth/gold", 55 );
	set( "special_defense", (["all": 25 ]) );
   set_natural_weapon( 12, 12, 12 );
   set_natural_armor( 86, 55 );

   wield_weapon( IANOBJ"coral_blade" );
   equip_armor( IANOBJ"shield" );

   set_lessons( ([
                  "anatomlogy" : ({ 250, 50 })
   ]) );
    set( "inquiry", ([
        "skill" : "�ޣ�С����ͨ����ѧ(anatomlogy)��\n",
        "wife" : "��.......\n",
        "cut" : "������Ҫ�赶��? �ҵļҴ������������!\n"
                "����ǰ������ĸ�����ҽ�����һ�ѵ�, �һ��صذ�������\n"
                "���ס�\n",
       "trace" : @REPLY
����, �ǹ�����Ҫ�����ҵİ�? ........

���Ի�����: �ǵ�, Ϊ�˱�ɱ��֮��, ��������Һͳ���
��ͷ��Ѱ����֮���䡣���ź�����, û�еõ��κ���˿��
��; ��Ȼ��������, ��Ҳ��ҹ���ݵ����Ҵ�ׯ����, ��..
..��..................

��������˵, �������ǵ��»�֮ҹ, ������������ʵ����
��ȥ����, ���������ȥ���������˼ҡ�����, ���˼��
Ů������, �������˵�����, �����ǲ����з�Ӧ��!
REPLY
     ]) );
}

void init()
{
   teacher::init();
   npc::init();
}

int check_trainee(object who)
{
   if( (int)who->query_quest_level("iywolf")<1 )
   return notify_fail(
        "���Ի�̾��: ��Ǹ��С������Ҫ������Ѱ���������١�\n" );
   if( (string)who->query("class")=="adventurer"
     && (int)who->query_level()> 4 )
   return 1;
   else return notify_fail(
   "���Ի�˵��: ��Ǹ�������ϷԸ�˵ֻ�̡ܽ��߼�ð���ߡ���\n" );
}
