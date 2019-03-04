#include "saulin_temple.h" 

inherit "/d/monk/guild/train_gonfu.c";
inherit ROOM;

void create()
{
	room::create();
	set_short("A protect gonfu room", "������ѧ���䷿");
	set_long( @LONG_DESCRIPTION
NEED TRANSLATE HERE.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
������������ѧϰ���ֲ�ͬ����������ѧ������\�����󲿷ݳ����ĵ������书\
���Ŷ��������һЩ������书\�����򱻷���¥�ϵ�������ʮ�����������ؾ���
������ǰ��һ�ѷ��Ƶľ���(scroll)������Ը����Լ��ĵ�����ѧ����ѡ�����ܹ�
ѧϰ���书\��Ȼ���ڴ˴�ѵ�� (train)��������һ��ע����֪(note)�㲻���ȿ��� 
���Ͽ��Իص��޺��ã�������ͨ�ڹ�\�ķ�����
C_LONG_DESCRIPTION
	);

    set("c_item_desc",([
         "note":@BOOK
������ѧ��������ս���й������˻�����Լ��Ĺ�\��ʹ�÷����� 

                  eungon [��\������] 
       Ȼ����     k      [��������]

������ѧǿ�����������кܴ�Ĺ�ϵ������Ҫ���ʹ�������������ȡ���\���ھ���  
�ڶ࣬�����㲻һ��Ҫÿһ����ѧ��������Ϊ���Ч����һ��ʱ�������죬��Ҫ�� 
�ǵ���������ֵ����ʱҪȥѵ��������ѧ���硣
(������ҽ�ƺͻ���Ĺ�\��һ��ֻ����ѡһ�á�)   
BOOK
	]));         

    set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
		"up"    : SAULIN"inner_room",
 		"south" : SAULIN"monk_guild" ]) );
                 
	set( "item_func", ([
		"scroll": "view_catalog" ]) );

	set_gonfu_type("general");
	set_gonfus( ([
        "tai-zuo"  : ({ "martial-art", 15,   800 }),
        "wu-sur"   : ({ "martial-art", 30,  2200 }),
	"da-mo"    : ({ "martial-art", 30,  2000 }),
	"fu-mo"    : ({ "martial-art", 60, 10000 }),
        "bolo-mi"  : ({ "martial-art", 25,  1000 }),
	"chu-han"  : ({ "martial-art", 85, 21000 }),
        "gi-mei"   : ({ "martial-art", 65,  8000 }), 
	]) );

	reset();
}
