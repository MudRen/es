#include "../healer.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(13);
        set_name( "four", "�Ĺ�" );
        add( "id", ({ "four" }) );
        set_short( "�Ĺ�" );
        set_long(
         "����һλ����ϤϤ, ��װ��ͦ����, ����������ü��, �����Ŀ����\n"
         "������ȫ��������͸��!\n"
        );
        seteuid(getuid());
        set( "alignment", -1000 );
        set( "race", "human" );
        set( "gender", "male" );
        set( "pursuing", 1 );
        set( "chat_chance", 40 );
        set("chat_output",({
             "�Ĺ�����ϤϤ�ض��㡺�ٺٺ١���Ц��Ц��\n",
             "�Ĺ�����ϤϤ�ؿ�����Ķ��ߣ�����˵�������ܡ�\n",
             "�Ĺ�һ�ְ������ϵĵľƸ����˹�ȥ�����๾�ࡱ�غȸ���⡣\n"
         }) );

}

