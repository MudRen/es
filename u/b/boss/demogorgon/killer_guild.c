//#pragma save_binary

// translation done 2-24-94. -Elon (having hard time translating)

#include </u/s/sage/guild/mudlib.h>
#include </u/s/sage/guild/stats.h>
#include </u/s/sage/guild/guilds.h>

#define BOARD "/u/s/sage/guild/killer_board"

inherit GUILD;
inherit DOORS;
void create()
{
    object guild_master;

        ::create();

    set_short("����");
        set_long(
                 @C_LONG_DESCRIPTION
    �����һ���ڵƺڻ�ķ��䣬һ�󺮷紵�����������˸����£���ĵ���
�и����㣬�ڷ��ӵ�ĳ�����䣬����һ˫��һ�����۾��ڶ����㣬ֻҪ��һ��
�ɾ��䣬��˫�۾��ͻ�����������Ȼ��������䷿���ȴ�����������Ӱ��
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
    �йر�������������������� help healers��
����������������������������������������������������������������������
LONG_TEXT
 ]) );
    set( "exits", ([
                  "north": "/u/s/sage/guild/gc",
                  "west" : "/u/s/sage/guild/killer_guild1",
        ]) );


        set( "pre_exit_func", ([
                "north" : "check_healer" ]) );
    //guild_master=new("/u/s/sage/test/");
    //guild_master->move(this_object());
       create_door("north", "south", ([
                    "keyword"       : ({ "tree door", "door" }),
                    "name"          : "tree door",
                    "c_name"        : "ľ��",
                    "c_desc"        : "һ�����õ�ľ��",
                    "status"        : "closed",
        ]) );

       // set_guild("monk");
        set_guild("/u/s/sage/guild/killer.c");
        BOARD->frog();
        reset();
}


