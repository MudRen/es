//#pragma save_binary

#include "farwind.h"

inherit ROOM ;

void create ()
{
        object obj ;

        ::create();
//      set_outside("farwind") ;
        set_short("¶��Ӣ�ۼ����");
        set_long(@C_LONG
������λ�Զ�����¶��Ӣ�ۼ���ݡ��ڲݵ�������һ������Ӣ��
פ��Զ����ͭ��(statue)���ഫ�⵽�����������������꣬�������
����(Pray)�Ļ������л��������������������
C_LONG
                );
        set( "light", 1 );
        set ("exits", ([
                "west" : FARWIND"bazz4",
                "east" : FARWIND"charch"
        ]) );
        set( "objects", ([
                "scroll": FARWIND"items/scroll" ]) );
        set( "no_monster", 1 );
        set( "PK_ZONE",1);
        set("item_desc",(["statue" :@C_WORD
����һ�������ͭ��Ӣ�۵�˫������Զ������������Ϸ���������į���ˡ�
��ͭ��ĵ�������һ��ͭ�ƣ�����д����

        Ӣ�ۣ�ʲ����Ӣ�ۣ�
        ��ֻ���� !! Ҫ����ÿһ���������˶�������������������
        Ҫ��ÿһ����������Ե���������ܱ�����΢Ц������˵����ġ�

                                        ����³˹ �� ����֮����
C_WORD
        ]));
   reset();
}

void init()
{
        add_action("revive_player","pray") ;
}

int revive_player(string str)
{
    object player;

    player = this_player();
    if( str && member_group(geteuid(player), "admin") ) {
        player = find_player(str);
        if( !player )
                return notify_fail("û�������!\n");
        if( !player->query("ghost") ) 
                return notify_fail( player->query("c_name")+
                        " �����ǻ���������!\n" );
        tell_object( this_player(), 
          "\n��ʹ�������ϵķ�����һ���漣�ƵĹ�â£����"+
          player->query("short")+"��\n"
        );
        tell_object( player, 
          "���ܵ��� "+this_player()->query("c_name")+" ʹ�������ϵķ���"+
          "��һ���漣�ƵĹ�â£�����㡣\n"
        );
        tell_room( this_object(), 
          "���ܵ��� "+this_player()->query("c_name")+" ʹ�������ϵķ���"+
          "��һ���漣�ƵĹ�â£����"+player->query("short")+"��\n" , 
          ({ player, this_player() })
        );
        player->set_temp("skip_dead",1);
    }
        else if(!player->query("ghost")) {
                write("��������Ӣ���ǵ�ͭ��ǰ����ϣ���ܳ�Ϊ���ǵ�һ���ӡ�\n");
                player->save_me();
                "/adm/daemons/backup"->user_backup(player);
                return 1;
        }
        else if( player->query_temp("skip_dead") )
          player->revive(1);
        else
          player->revive();
        return 1;
}
