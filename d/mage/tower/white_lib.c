//#pragma save_binary
#include "/d/mage/mage.h"

inherit "/d/mage/study1";
inherit ROOM;

void create()
{
        ::create();
        set_short("A white room", "��ħ��ͼ����");
        set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
                , @C_LONG_DESCRIPTION
������������ɫ֮���в�����ḻ��һ��ͼ���ң��������ղ��йذ�ħ����
������鼮���κεط�Ҳ�Ȳ��ϵģ�����Ŀǰħ��ʦ�ǹ�Ϊʹ�õļ���ħ��
֮�⣬��Щ�鼮�������صķ��������ڻ�û�����ܿ���������Է��ĵ�һ��
����ϵ�����(index)������Ŀǰ����Щ�������Բο�,������ͨ��ͼ��ݴ�
����ͨ����
C_LONG_DESCRIPTION
        );
    set( "no_monster", 1);
        set( "light", 1 );
        set( "exits", ([ 
                "east" : MAGE"library" ]) );
        set( "item_func", ([
            "index" : "view_catalog" ]) );
        set_spells( ([
                "antidote"       : ({ "white-magic", 40, 4, 15, 150 }),
                "heal"    : ({ "white-magic", 40, 4, 15, 150 }),
                "paralyze"       : ({ "white-magic", 40, 4, 15, 150 }),
    "power-boost" : ({ "white-magic", 40, 4, 15, 150 }),
      "protect"    : ({ "white-magic", 40, 4, 15, 150 }),
        ]) );
        reset();
}
