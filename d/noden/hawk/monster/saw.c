inherit MONSTER;
#include "../hawk.h"
int help1 = 0;
void create()
{
        ::create();
        set_level(8);
        set_name( "tailor","�÷�ʦ" );
        add("id",({"tailor"}) );
        set_short( "�÷�ʦ" );
        set_long(@LONG
�㿴��һ����Ͳ���Ĳ÷�ʦ������Ĺ�������ʹ������춷��ҹ���������죬
�����㿴����ɫ�ƺ����ƣ�������˳�ֵĹ��߲����ˣ�������ܰ�æ(help)���һ�
���Ķ��������ܻ�������а����ġ�
LONG
        );
        set( "inquiry", ([
                "help" : "@@help_me",
                "dry" : "@@dry_paper"]));
        set( "alignment", 100 );
        set( "gender","female" );
        set( "race","gnome" );
        set( "time_to_heal", 10 );
        set_natural_armor( 20, 12 );
        set_natural_weapon( 25 , 13 , 17 );
        set( "wealth/silver", 10 );
}

int dry_paper(object who)
{
        object paper1;
        if (this_player()->query_temp("help_tailor") == 0)
        {
                tell_object(this_player(),
                "����Ѷ�����Ǭ����Ҫ���ȵĶ���ȥ�氡���������Ļ�����"+
                "���԰���棬��\n����Ҫ�Ȱ���(help)�����¡�\n");
                return 0;
        }

        if (this_player()->query_temp("help_tailor") == 2)
        {
                tell_object(this_player(),
                "��Ҫ��ɶ��������С�Ĳ�Ҫ�յ��ˣ���������������ˡ�\n");

                if (!present("paper",this_object()))
                {
                        tell_room(environment(),
                        "�÷�ʦ˵����ֽ�����ҵĻ����ҿ�û�취����ࡡ�\n",
                        this_object()
                                 );
                        return 1;
                }

                tell_room(environment(),
                        "�÷�ʦ��"+(string)this_player()->query("c_name")+
                        "�������ϵ�СֽƬ��Ǭ�ˡ�\n",this_object()
                         );
                paper1 = new(OBJ"paper1.c");
                paper1->move(this_object());
                command("give paper to "
                        +(string)this_player()->query("name"));
		this_player()->set_explore("noden#41");
                return 1;
        }
}

int help_me()
{
        if (this_player()->query_temp("help_tailor") == 2)
        {
                tell_object(this_player(),
                        "�÷�ʦ˵��Ϊ�˸�л������ҵ����ҵ��ٶ�����ʲ����Ҫ"+
                        "�Ұ�æ����;���˵�ɡ�\n" );
                return 1;
        }

        if (this_player()->query_temp("help_tailor") == 1)
        {
                if (!present("iron") )
                {
                        tell_object(this_player(),
                        "�÷�ʦ˵���ǳ�лл������ң�������ٶ������Ұɡ�\n" );
                }
                else if (present("iron") )
                {
                        tell_object(this_player(),
                        "�÷�ʦ�����ٶ����˵Ľ�: �� ��~~~~���ֿ��Ի�"+
                        "ȥ���ҵĹ����ޡ���\n");
                        command ("kiss " +
                           (string)this_player()->query("name"));
                        this_player()->set_temp("help_poet",2);
                }
        return 1;
        }
	if (help1 == 1)
	{
		tell_object(this_player(),@LONG
�÷�ʦ˵���ţ��и�����Ϊ��������˵Ҫ�������ˣ��Ǿ�лл��ĺ����ˡ�
LONG
		);
		return 1;
	}
		
        tell_object(this_player(),@LONG

�÷�ʦ������һ�ۣ�˵��
    �ܾ���ǰ������������ʧ��һ���ٶ�����֪��������������Ҳ��п�����
��һ��ɽ��׷�ϵĻ����е��ġ�ϣ�����ܰ����һ���������һ����Ļ�����ʲ
�����ܰ����æ�ģ����ܿ��ڰɡ�
LONG
        );
	help1 = 1;
        return 1;
}

