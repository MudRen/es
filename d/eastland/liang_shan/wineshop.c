#include "takeda.h"
#include <money.h>

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "��ɽ�Ƶ�" );
        set_long(@LONG
��������ɽ�����ľ�¥��ɽկ�ڵ�ɽ�����ܵ�����ڻ������ˣ���
����������������������ʳ��ο���Լ���˳�㽻�����еľ�����������
С��æ��æ�����Ե�ʮ�����֣�һ����ľ��㣬�����˱Ƕ������㲻����
�ü����ꤣ�ʳָ�󶯣��������ϰ�ѯ�ʼ�Ǯ(menu)��
LONG
        );
        
        set( "exits", ([ 
        	"east"  : TROOM"path2" ,
        ]) );
        
        set( "objects", ([
                "owner" : TMONSTER"zhan1",
                "owner_wife" : TMONSTER"sun1",
                "guest" : TMONSTER"traveller"
        ]) );
        reset();
}
int clean_up() { return 0; }
