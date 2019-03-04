#include <mudlib.h>

inherit MONSTER;

void create()
{
   object weapon;

	::create();
	set_level(13);
   set_name( "Moorth Spy", "Ĭ��˹���" );
   add( "id", ({ "spy" }) );
   set_short( "Ĭ��˹���" );
	set_long(
         "����Ĭ��˹���(army)�ɳ��ļ��, ����Ŭ���ش�̽����(news)��\n"
	);
   set( "alignment", -500 );
	set_perm_stat("str",16);
	set_perm_stat("dex",15);
	set_skill("parry", 50);
   set_skill( "dodge", 60 );

	set( "race", "human" );
	set( "gender", "male" );
   set_natural_armor( 40, 10 );
   set( "pursuing", 1 );
   set( "moving", 1 );
   set( "speed", 10 );
   set( "patrol", ({ "east", "west", "west", "west", "west", "east",
          "north", "south", "east", "east" }) );

   wield_weapon( "/d/moorth/obj/shortsword" );

   set( "inquiry", ([
          "news" : "@@ask_news",
          "reward" : "@@ask_reward",
          "inform" : "@@ask_inform",
          "army" : "���ǵĴ����׼������ŵ�����ǳ�, Ҫ��������!\n" 
        ]) );
}

int ask_news(object who)
{
   if( (int)who->query_level()<5 ) {
     write( "�߿�! �߿�! ����С�����!\n" );
     return 1;
   } else {
   tell_object( who, @LONG
�ٺٺ�...û��! �������ռ��鱨, ��������ṩ������������
�鱨(inform), �㽫��õ��ܴ�ĺô�(reward)!
LONG
     );
     return 1;
   }
   return 1;
}

int ask_inform(object who)
{
   if( (int)who->query_level()<5 ) {
     write( "�߿�! �߿�! ����С�����!\n" );
     return 1;
   } else {
   tell_object( who, @LONG
���ǵľ���һֱ����������ǳ�, �����Ǹ��ؾ����������
�����ǵ��ж�����ָ��, Ҫ���������ͺ���!
LONG
     );
     return 1;
   }
   return 1;
}

int ask_reward(object who)
{
   if( (int)who->query_level()<5 ) {
     write( "�߿�! �߿�! ����С�����!\n" );
     return 1;
     }

   if( who->query_temp("war_spy") ) {
   tell_object( who, @LONG
�ܺ�, �ǳ���л��İ���! ����Ҳ���˿����㻹����!
���ǵ������õ��ͽ�.
[ Ĭ��˹����ó�һ��Ǯ�Ҹ��� ]
LONG
     );
   who->credit( "silver", 777 );
   who->delete_temp( "war_spy" );
   who->set_explore("noden#15");
   return 1;
   } else {
     write(
"����Ǹ�������ȥ, �������ڸ����ϻ���(brandish)�����彣\n"
"֪ͨ�Ҿ��Ļ�, �ҽ�����һ���Ӵ���ͽ�! ����...\n"
"���ǵĴ�������ײ���, ɱ�˲�գ�۵���!\n" );
     return 1;
     }
   return 1;
}
