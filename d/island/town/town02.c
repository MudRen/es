#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("ӳ������");
     set_long(@C_LONG
����ӳ��������ĵ���Ҫͨ��֮һ�������Ͼ��Ǵ���Ĺ㳡���Ƕ���
�����ɵ���ٵĵط�����������κ���Ҫ��Ӧ�ö��������Ƕ��ҵ�����
�Ϸ��Ĳ�Զ������һ���ǳ����۵İ�ɫ�������Ǿ��Ǻ�ƽ�����ã�������
�۹���ˣ���Ӧ��ȥ�Ƕ���һ�䡣������һ����վ������������ʿս����
����������ǽ����Щ��(word)��
C_LONG
             );
     set_outside("island");
     set("item_desc",(["word":@LONG
      
     ��ڲ����������
LONG
     ]));
     set("light",1);
     set("exits",([
               "east"   : ITOWN"post_office",
               "north"  : ITOWN"town01",
               "south"  : ITOWN"square01"
            ]) );
     reset();
#include <replace_room.h>     
 }