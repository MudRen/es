#include <mudlib.h>
#include <stats.h>
#include <org.h>
#include "../god.h"
#include <ansi.h>

#define BOARD GOD"god_board"

inherit NEW_GUILD;
void create()
{
    object guild_master;

        ::create();

    set_short("ħ�񹫻�");
        set_long(
                 @C_LONG_DESCRIPTION
����������ħ����޵��ֵأ���������������½��а��ĵط�����Ȼ��
��а��ĵط�����ͬ�����е����Ǻ��Ѻ�,�м���һ��а��(sword)����
�������֣�runes),�㲻֪��������ȥ������
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "c_item_desc", ([
                "runes" : @LONG_TEXT
    ������������������������������������������������������������
      ��ӭ������һ�Σ������һЩ�߼�����Ŀ���(������ǵͼ����
      ��Ҫ�����ġ�Ŭ���ܶ�һ����ƽ�����ƣ�����ͷ�ص�,��ʱ������
      ��ӭ����롣)������˽Ȿ������������
              (help guild)��             (read book)��
      ������������������������������������������������������������
LONG_TEXT
,
                "sword" : HIB "��а���ƺ�����ĳ�ֲ���˼���ħ����\n" NOR
 ]) );
    set( "exits", ([
                  "east" : "/d/god/guild/pk.c",
                  "south" : "/d/god/guild/shop.c",
                  "west" : "/d/god/guild/tech.c",
        ]) );
        set_guild("god");
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
        write("
"+HIY"���������ǻ���һ�棬а�������������ֻ��PK
��Ҳ��ܵõ�������������\n"
"�����Ҫ�þ����������ɹ�������һ���궼����
��(ES��ʱ��)����ɱ��ҡ�\n"
"��Ψһ�������ĵġ����顱��\n\n\n"
"�������ṩ��������������Ϊ:(����������POST)\n\n"
   "      ����: 30            �ǻ�: 40\n"
   "      ����: 35            ����: 25\n"
   "      ��: 10            ����: 30\n"+NOR""
              );
        return 1;

}
