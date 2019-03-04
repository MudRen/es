#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "С·" );
	set_long(@LONG
����һ����ͼ���Ҳ�����С·�����Գ����˳�����«έ�����ҡҷ��	  
��˵��������徶ǿ�˳�û�����ǻ᲻��Ͷ���«������? �㲻���࿴
�˿�«έ(weed)�����
LONG
   );
        set("c_item_desc",(["weed":
"����ϸ�Ŀ�����һ���«έ��һ���������ͻȻ����«έ�����ƺ�����\n"            
"���죬Ҳ��\�����������ȥ(pass)����....\n"            
            ]));        
	set_outside("eastland",1);
        set( "exits", ([
                "north" : TROOM"out2",
                "south" : "/d/eastland/1,12.east"
        ]) );
        reset();
}
void init()
{
add_action("do_pass","pass");
}

int do_pass(string arg)
{
 if ( !arg || arg != "weed")
    return notify_fail("pass ʲ��? Ҫ all pass �Ϳ�ȥ����� !\n");
 if ( present("mountain thief"))  
 	return notify_fail("ɽ��������ס�������Ŀ����� ...\n");
    write ("�����ַֿ�«έ�ԣ�һͷ���˽�ȥ...\n");
    tell_room(this_object(),
    "�㿴��"+this_player()->query("c_cap_name")+ "һͷ�����«έ��.....\n" ,
    this_player());
    this_player()->move_player(TROOM"lake/beach10","SNEAK");
return 1;
}
int clean_up() { return 0; }    