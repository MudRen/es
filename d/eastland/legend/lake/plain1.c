#include <mudlib.h>
#include "../legend.h"
inherit ROOM;

void create()
{
    ::create();
    set_short( "plain0", "С��" );
    set_long(@C_LONG
��������һ������С��,С����������һ���Ų�֪������ľ,��֦��ס������,
�Ե���Щ����,����һЩ������౵ؽ������㶫����һ����,���ϲ�̶��ӳ,һ
����������,һֻֻ�İ���˿��ɻ�ͣ,ɷ����Ȥ�������и���ʾ�� ( sign ) ��
C_LONG
    );
    set( "light",1);
    set( "can_use_sea_ball",1);
    set( "exits", ([
     "west":LAKE"plain0"
    ]) );
    set("c_item_desc",([
            "lake":"һ����ɫ�Ĵ����\n",
            "sign":@LONG
һ�����ƾɵ�������д��:


          �أء��ο�ֹ��!!���أ�
    
    
       �������ֺ��в�ʱ�����ֳ���,�˵�����Ϊ��������!!
       ���,�벻Ҫ�����ﶺ��,���Ͻ��Ҷ�����������!�м��м�!                  
   
   
   
LONG    ]) );
    set("pre_exit_func",([
        "tunnel":"can_pass"]));
    reset();
}

int can_pass( string arg )
{
    if ( !query("exits/tunnel") ) 
       return 1;
    if ( present("water beast",this_object()) ) {
       tell_object(this_player(),
         "��֧���Ծ޴��������������ǰ�������ȥ..\n");   
       return 1; 
    }
}

void reset()
{
    delete("exits/tunnel");
    delete("exit_suppress");
    delete("c_item_desc/water-tunnel");
    ::reset();
}