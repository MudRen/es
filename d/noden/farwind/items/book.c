#include <mudlib.h>;
#include <config.h>;

inherit OBJECT;
inherit DAEMON ;

int read_me = 0;

void create()
{
        seteuid(getuid());
        set("id",({"story"}));
        set_name("story","�������¼�");
        set_short("�������¼�");
        set_long(
                "����һ�����ض�����½�Ĺ��ϴ�˵�Ĺ��¼���\n");
        set( "weight", 30 );
        set("unit","��");
        set("value",({20,"silver"}) );
}

void init()
{
  add_action("read_me", "read");
}

int read_me (string str)
{
        object who,monster;
        who=this_player();
        
        if (!str)        
            return notify_fail("��Ҫ��ʲ�ᶫ��ѽ?\n");
                 
        if (str!="story")     
            return 0;

        if (!read_me)
{
        say(who->query("c_name")
                +"���ڶ�һ���飬�����ǡ��������¼�����\n");
        tell_object(who,@LONG
���ϼ�����:
��˵�ں�����һ���и����ϵĹ��ң����ж������������������Ƕ�������ʳ��
��سɽ�.......

��? �������ҳ��������, �����Ǳ������������!
LONG
        );
        if ( (int)who->query_quest_level("bookbug") > 0 )
        return 1;

        tell_object(who,@LONG
���㷭�Ĺ��¼�ʱ, ��Ȼһֻ���ཱུ������鱾�е��˳���!
LONG);
        monster = new( "/d/noden/farwind/monster/bookbug" );
        monster->move(environment(who));
        who->set_temp("findbug",1);
        read_me = 1;
        return 1;
}
        tell_object(who,@LONG
����ϸ���Ķ�������д���֣���ͼ����������д���֣�����ʵ��
�Ǳ�������̫������....��Խ��Խ������ʵ����ѿɶ�������
�ҳ���һ�Ų���й�ޡ�
LONG
        );
        return 1;
}

