#include "../echobomber.h"
//	#define BOARD "/u/e/echobomber/board/board"

inherit ROOM;

void create()
{
        ::create();
        set("light",1);
        set_short("������ص���ͷ");
        set_long(@Long_Description
������һ���򵥶��Ͼɵ���ͷ.������һ��������Ƶ�����(cliff),����,��,��
������������( ocean ).�̹ǵ����Ӻ��ϴ���,�Լ����õ�����( plants )��
�����Ķ���ζ��,��������뿪���ｫ����õ�ѡ��.
�������Ѿ�̤�����������--------һ��������������Ƹ��ĵط�.����������Ƶ�
������,�������˾��µ�ɽ������ ,�Լ�����û�˼����ĺ�����( Skeletons ).Ŀǰ
�ڰ����������������������.���˼���а��İ�������.
Long_Description

 );
set_outside( "deathland" );
 set("item_desc",(["cliff":@C_CLIFF
�ܸߵ�����.�кܶ������ֲ������������,����������Ƿ�������ȥ,��
���㲻ȷ���������Ƿ���֧���������.
C_CLIFF

,"plants":@C_PLANTS
����ע����Щ���õ�ֲ��ʱ,�㷢����һЩ����(writings)�������.
C_PLANTS

,"writings":@WRITINGS
���ҽ�ҪԶ�����Σ�յĵط�ʱ,�Һ��������Ի���.������ð����ѽ,Ϊ��
�����ܹ������ҵĴ���,����һЩ����
 ----Ǳ��(dive)ˮ��,����(climb)��ɽ.------
     ð�ռ�  ��Ĭ
WRITINGS

,"ocean":@C_OCEAN
һƬ�����
C_OCEAN
                               ]));

set("exits",([
    "northeast":Deathland"/main/p1",
      
   ]));

//	BOARD->frog();

}
void init()
{
     add_action("to_climb","climb");
     add_action("to_dive","dive");
     if( !find_object("/d/std/ocean/ship_death") )
     	"/d/std/ocean/ship_death"->frog();
     if( !find_object("/d/std/ocean/ship_ta_tong") )
     	"/d/std/ocean/ship_ta_tong"->frog();
}

int to_dive()
{
   write("��Ǳ�뺣��֮��.\n");
   this_player()->set_explore( "deathland#0" );
   this_player()->move_player(Deathland"/main/d4.c",
         ({"%sǱ�뺣�ж���ʧ��\n","%s����ͷǱ��������\n"}),"SNEAK");
   return 1;
}

int to_climb()
{
  if ((int)this_player()->query_skill("climb")>100) {
   write("ƾ���߳����ʵǾ���,������������\n");
   this_player()->move_player(Deathland"/upper/a1","SNEAK","");
   }
   else {
   write("�����Լ��ļ���,Ҫ����ȥ��ֱ������.\n"
      "��ֻ������Ѱ�ҳ�·.\n");
   }
   return 1;
}
