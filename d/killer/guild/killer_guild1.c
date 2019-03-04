//sage �޸��ڣ� 98-4-18 11:10

////#pragma save_binary

#include <mudlib.h>

inherit ROOM;

int cup;
int open=0;


void create()
{
        ::create();
        set_short("ͣʬ��");
        set_long( @C_LONG_DESCRIPTION
    �����ǹ���ڷ�����ĵط����������󣬲����˴��СС�Ĺײ�(coffin)��
ֻҪ��Ϊ����������ģ�������ʸ�����������������ʥ�ĵط�����˵����
����������䣬��ԶҲ���ḯ�á�
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "item_desc", ([
                "coffin" : "��Щ�ײ�ʮ���Ͼɣ���������˻ҳ���������ϸ�鿴һ�飬\n"
                          "�����ƺ�ÿ���ײĶ����Դ�(open)���������������ȥ \n"
                          "������\n"
        ]) );

        set( "exits", ([
         "east" : "/d/killer/guild/killer_guild.c" 
        ]) );
}
void init()
{
        add_action( "do_open", "open" );
        add_action("enter_hole", "enter");
}

int do_open(string str)
{
    if( !str || str != "coffin" )
      return notify_fail("��Ҫ��ʲ��?\n");
    if( (int)this_player()->query_stat("str") < 15 )
      return notify_fail(@ALONG
���þ���ȫ���������������Ϊ����̫С��̧������
���Ѿ���֫�������ڵ��ϴ�����
ALONG
      );

    tell_object( this_player(),@C_LONG
�������ش򿪹ײĵĶ��ǡ�ͻȻ��������ֵ������ӹײĵĵײ�����������
�Ǵ�����ʲ����ء������ͷһ�����ײĵײ�������һ��С��(hole)
C_LONG
    );
    open = 1;
    return 1;
}
int enter_hole(string str)
{
      if( !str || str != "hole" )
        return notify_fail( "��Ҫ��ȥ����?\n");
      this_player()->move_player("/u/s/sage/workroom");
      return 1;
}
void reset()
{
        ::reset();
        open = 0;

}
