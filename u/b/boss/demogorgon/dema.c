
#include </u/b/boss/demogorgon/mudlib.h>
#include </u/b/boss/demogorgon/stats.h>
#include </u/b/boss/demogorgon/guilds.h>
#include <ansi.h>

#define BOARD "/u/b/boss/demogorgon/board"

inherit GUILD;

void create()
{
        ::create();
      set_short( "ħ�񹫻�" );
set_long(
"����������ħ����޵��ֵأ���������������½��а��ĵط�����Ȼ����а
��ĵط�����ͬ�����е����Ǻ��Ѻã��м���һ��а��(sword)���������
�֣�runes),�㲻֪��������ȥ������\n",
        );

        set( "light",1 );
        set( "exits", ([
    "east" : "/u/b/boss/demogorgon/guild1.c",
    "south" : "/u/b/boss/demogorgon/shop.c",
    "west" : "/u/b/boss/demogorgon/guild2.c",

        ]) );

        set("item_desc", ([
                "runes" : CYN
" ����������������������������������������������������������
   ��ӭ������һ�Σ������һЩ�߼�����Ŀ���(������ǵͼ����
   ��Ҫ�����ġ�Ŭ���ܶ�һ����ƽ�����ƣ�����ͷ�ص�,��ʱ������
   ��ӭ����롣)������˽Ȿ������������(help guilds)��
   (help damogorgon)��
   ���������������������������������������������������������� \n"NOR,
                "sword" : HIB "��а���ƺ�����ĳ�ֲ���˼���ħ����\n" NOR
        ]) );


       // set_guild("mage");
        set_guild("/u/b/boss/demogorgon/dema.c");
        BOARD->frog();
        reset();

}

#include </u/b/boss/demogorgon/mudlib.h>
#include </u/b/boss/demogorgon/stats.h>
#include </u/b/boss/demogorgon/guilds.h>
#include <ansi.h>

#define BOARD "/u/b/boss/demogorgon/board"

inherit GUILD;

void create()
{
        ::create();
      set_short( "ħ�񹫻�" );
set_long(
"����������ħ����޵��ֵأ���������������½��а��ĵط�����Ȼ����а
��ĵط�����ͬ�����е����Ǻ��Ѻã��м���һ��а��(sword)���������
�֣�runes),�㲻֪��������ȥ������\n",
        );

        set( "light",1 );
        set( "exits", ([
    "east" : "/u/b/boss/demogorgon/guild1.c",
    "south" : "/u/b/boss/demogorgon/shop.c",
    "west" : "/u/b/boss/demogorgon/guild2.c",

        ]) );

        set("item_desc", ([
                "runes" : CYN
" ����������������������������������������������������������
   ��ӭ������һ�Σ������һЩ�߼�����Ŀ���(������ǵͼ����
   ��Ҫ�����ġ�Ŭ���ܶ�һ����ƽ�����ƣ�����ͷ�ص�,��ʱ������
   ��ӭ����롣)������˽Ȿ������������(help guilds)��
   (help damogorgon)��
   ���������������������������������������������������������� \n"NOR,
                "sword" : HIB "��а���ƺ�����ĳ�ֲ���˼���ħ����\n" NOR
        ]) );


       // set_guild("mage");
        set_guild("/u/b/boss/demogorgon/dem.c");
        BOARD->frog();
        reset();

}
