#include <mudlib.h>

//inherit ROOM;

inherit "/std/room/std_storage.c";

void create()
{
	::create();
	set_short("������");
	set_long(@LONG
������һ�䴢���ң�����ɢ����һЩ������װ��������Ϊ���ù����е�����
�ܹ����Ž����ģ�Ҳ��Ϊ���ܹ�������������ˮ˼Դ֮�ģ��ܳ��漺�����ˡ�
������˵��ػ���ǽ������һ�Ÿ�ʾ(note)��
LONG
	);
 /*       
        set( "item_desc", ([
             "note": "������������������������������Ҫ���ʵ�,�ռ�����\n"
                     "�벻Ҫ�������Ѱ�Ķѷ�����;�Ķ�����\n"
           ]) );
*/
	set("exits", ([
		"down"	: "/d/scholar/scholar/embattle_room",
		]) );
        set("light",1);
     //   set("container_res",1);
       set("weapon_res",({20,13}));
       set("armor_res",([
                         "body" : 20   , "legs"   : 7 ,
                         "feet" : 6    , "cloak"  : 8 ,
                         "head" : 5    , "arms"   : 4 ,
                         "misc" : 6    , "finger" : 5 ,
                         "hands" : 5   , "globe"  : 23 ,
                         "shield" : 6  , "saddle" : 9 ,
                         "kernal" : 4  , "tail"   : 8 ,
                         "others" : 6,
                         ]) ) ;
        set("max_amount",50);
        set("class_name","scholar");
        set("msg_arg","��è");
        reset();  
}

