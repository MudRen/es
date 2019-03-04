#include "hawk.h"

inherit ROOM;

int hole;

void create()
{
        ::create();
        set_short("ɽ��");
        set_light(1);
        set_long( @LONG_DESCRIPTION
������һ�����ֲ�����ָ������ɽ�ȵף���ΧһƬ��ãã�ģ�ͷ��
������ͣ���ڵ�ˮ�����µĸ���Ҳ���ϵ�ɢ�������ĵ����������ܵ�֩��
���������������������ȫ��ס�����ȥ·���㿴�˰��죬���ǲ�֪����
�����뿪����ֲ��ĵط�������"Quit"������Ψһ��ѡ�񣬲���Quit�Ļ�
���ǸϿ��ڡ����ܡ����ң�������ʲ�᷽�������뿪�����ط���
LONG_DESCRIPTION
);
        set("c_item_desc",([
                "tunnel":"@@to_tunnel"
                        ]) );
        set("objects", ([
                "bug" : MOB"spider"
                        ]) );

    reset();
}//end of creat

void init()
{
	call_out("report",1,this_object() );
        add_action("to_go","go");
        add_action("to_find","search");
        add_action("to_enter","enter");
}

void report(object holder, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( ��%s )\n","/adm/daemons/statsd"->status_string(victim)));
}

int to_go()
{
        if ( present("spider",this_object()) )
        {
           tell_object(this_player(),"֩��������צ�����������ȥ��\n");
           return 1;
        }
        tell_object(this_player(),"����û���κγ�·��\n");
        return 1;
}

string to_tunnel()
{
        if ((this_player()->query_temp("find_hole") == 1) && (hole == 1))
        {
                return "һ����ɭ��ʪ�ĵض�����Ҫ��ȥ(enter)��\n";
        }
        else
        {
                return "���뿴ʲ�᣿\n";
        }
}

int to_find(string s)
{
        if (present("spider"))
        {
                tell_object(this_player(),
                        "֩��������צ�����ŵò����Ҷ���\n");
                return 1;
        }

        else if (s != "everywhere")
        {
                tell_object(this_player(),
                        "���������ң���û�з����κζ�����\n");
                return 1;
        }
        else
        {
                tell_object(this_player(),
                        "�㵽��������ȥ�������ڶ����ǵĴ����ԣ��ҵ�"+
                        "һ��С�ص�(tunnel)��\n");
                this_player()->set_temp("find_hole",1);
                hole = 1;
		this_player()->set_explore("noden#40");
                return 1;
        }
}

int to_enter(string s)
{
	if ((this_player()->query_temp("find_hole") == 1) && (hole == 1) && s == "tunnel")
        {
                tell_room(environment(this_player()),
                "�㿴��"+this_player()->query("c_name")+
                "��һ���굽����ȥ�ˡ�\n",
                this_player() );
                tell_object(this_player(),
                        "��һͷ�Խ�����ܵ���һ���ط��ޡ�\n");
                this_player()->move_player(HAWK"room1-1","SNEAK");
                return 1;
        }
        tell_object(this_player(),"�����ȥ���ʫĦ���Ĺ뷿��\n");
        return 1;
}

void reset()
{
        ::reset();
        hole = 0;
}
