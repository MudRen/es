//sage�޸��ڣ�98-4-19 8:21////#pragma save_binary

// translation done 2-24-94. -Elon (having hard time translating)

#include <mudlib.h>
#include <stats.h>
#include <org.h>
#include "../killer.h"

#define BOARD KILLER"killer_board"

inherit NEW_GUILD;
inherit DOORS;
void create()
{
    object guild_master;

        ::create();

    set_short("ɱ�ֹ���");
        set_long(
                 @C_LONG_DESCRIPTION
    �����һ���ڵƺڻ�ķ��䣬һ�󺮷紵�����������˸����£���ĵ���
�и����㣬�ڷ��ӵ�ĳ�����䣬����һ˫��һ�����۾��ڶ����㣬ֻҪ��һ��
�ɾ��䣬��˫�۾��ͻ�����������Ȼ������䷿���ȴ�����������Ӱ��
    һ���������ڷ��ӵ����м䡣
    �ڽ�������һ���Ѿ���ù��ֽ(paper)�����þ����о���������ϡ����һ��
üĿ��
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "c_item_desc", ([
                "paper" : @LONG_TEXT
����������������������������������������������������������������������
��ֽ��д��:
    ������Ϊ������ǿ֮���ᣬ�������ѧ��������˫���书�����Գư����磬
�������ޣ�������١�
    
    ��ϸ����������� help guild �Ķ�˵����
����������������������������������������������������������������������
LONG_TEXT
,
                 "book":"����һ������ɱ�ֹ������������ε��顣�����read����\n"
 ]) );
    set( "exits", ([
                  "north": "/u/s/sage/guild/gc",
                  "west" : "/d/killer/guild/killer_guild1",
                  "east" : "/u/s/sage/guild/killer_guild3",
        ]) );


        set( "pre_exit_func", ([
                "west" : "check_killer" ]) );
    guild_master=new("/d/killer/monster/blowblood");
    guild_master->move(this_object());
       create_door("north", "south", ([
                    "keyword"       : ({ "tree door", "door" }),
                    "name"          : "tree door",
                    "c_name"        : "ľ��",
                    "c_desc"        : "һ�����õ�ľ��",
                    "status"        : "closed",
        ]) );

        set_guild("killer");
        BOARD->frog();
        reset();
}
void init()
{
        ::init();
        add_action( "do_read", "read" );
}
int do_read(string arg)
{
        if( !arg || arg!="book" ) return 0;
        write("�������ʱ����û��ʱ�䣬��������һƬ�հ�....��\n");
        return 1;
}
