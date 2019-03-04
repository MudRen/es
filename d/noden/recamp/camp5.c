#include <mudlib.h>
#include "camp.h"
inherit ROOM;

void create()
{
	::create();
   set_short("�ص�");
   set_long( @LONG_DESCRIPTION
�������صĵص������������ƺ��൱��Զ������ȴ�൱�Ŀ����̣�������
����ҫ�����������ӣ���������ͨ�������ϻ���������ֵֹĶ���ͼ�����벻֪����
���ģ��൱�����˵����⡣���ϻ����и�����(sign)��
LONG_DESCRIPTION
);

   set("light",1);
   set( "exits", ([ 
    "up"   : CAMP"camp4",   
    "east" : CAMP"camp6",  
    "west" : CAMP"camp8", 
   ]) ) ;

   set( "item_func", ([ 
    "sign":"look_sign", 
   ]) ) ;

   set( "objects", ([ 
	"mob1" : CAMPMOB"mob1"
   ]) );

   reset();
}

// int look_sign()
// {
//  write("    /~~~~~~~~~~~~~~~~~~~~~~~~~~~/~\\  \n"
//        "   | It is a great invention   |___| \n"
//        "   |     of ink && paper ..    |     \n"
//        "/~~~~~~~~~~~~~~~~~~~~~~~~~~/   |     \n"
//        "\\__________________________\\__/      \n") ;
//   return 1 ;
// }


int look_sign()
{
 write("    /~~~~~~~~~~~~~~~~~~~~~~~~~~~/~\\  \n"
       "   |    ����һ����           |___| \n"
       "   |            īˮ��ֽ��     |     \n"
       "/~~~~~~~~~~~~~~~~~~~~~~~~~~/   |     \n"
       "\\_________________________\\__/      \n") ;
  return 1 ;
}
