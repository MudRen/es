#include "../mad.h"

inherit MONSTER;

void create()
{
	::create();
   set_level(5);
   set_name( "guey Father", "���ϵ�" );
   add( "id", ({ "guey", "father" }) );
   set_short( "���ϵ�" );
	set_long(
        "�㿴��һ��״�Ƴմ�, ��Ƽ��ݵ���ͷ, ������������������ա�\n"
        "�����㲻ʱ����һ�����ĵ���, �������޵�̾Ϣ����\n"
	);
   set( "race", "human" );
	set( "gender", "male" );
   set_skill( "dodge", 50 );
   set( "wealth/copper", 10 );
   set( "alt_corpse", IANMOB"zombie1" );
	set( "inquiry", ([
       "sheaumei" : "@@ask_name"
	]) );
}


void ask_name(object player)
{
	if( query_attacker() ) {
            tell_room( environment(),
              "���ϵ�ŭ���: �ֳ�����һ������! ��������ʰ��!\n",
			this_object() );
	} else {
            tell_room( environment(),
                 "���ϵ�ŭ���: Ϊ����Ҫ������Ů��������? ��! ��һ��������! �µ�����!\n",
			this_object() );
		kill_ob( player );
	}
}

void die()
{
        tell_room( environment(this_object()), 
          "\n���ϵ���������, ��֧����........\n\n"
          "����������ȥʱ............\n\n"
          "ͻȻ���ϵ���վ������, ����������! ԭ�����ϵ��ǡ��䰡!!\n\n"
          , this_object() );
        ::die(1);
}
