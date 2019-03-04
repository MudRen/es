#include "goomay.h"
#include <money.h>

inherit ROOM;
inherit "/std/seller";

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short("����Ӵ��¥" );
        set_long(
@LONG
�����ǹ�÷�����ľ�¥���۽������װ��������һ�ɸ����ֵ���Ϣ��
����һ���Ű������Ĵ���������������ˮй��ͨ��������С��æ��æ����
�Ե�ʮ�����֣���̨��һ����������С�����ƹ�Ц����ĺ�ÿһ�����˴�
�к�����������ӵ�����һ���Ǹ�·Ӣ��������÷���Ŀ��֮һ�������
���˳��������������ʼ�Ǯ(menu)��
LONG
        );
        
        set( "exits", ([ 
        	"west"  : Goomay"mgate" ,
		"north" : Goomay"row13",
		"up"    : Goomay"wine_shop2",
        ]) );
        
        set_inventory( ({
                       ({ "/d/noden/farwind/items/ching.c",10,10}),
                       ({ "/d/noden/farwind/items/xo.c",10,10}),
                       ({ "/d/noden/farwind/items/rose.c",10,10}),
                       }) );

        set( "objects", ([
                "shop owner" : Mob"wine_owner",
                "girl"       : Mob"tang_ying",
        ]) );
        reset();
}

void reset()
{
     room::reset() ;
     seller::reset() ;
     return ;
}
