#include "iigima.h"
inherit ROOM;

void create()
{

        ::create();
        set_short( "hilove temple","ϣ³ܽ���");
        set_long(
        @C_LONG
���Ŀռ䣬�����У����װɣ��㿴�˲���Ϊ�ڰ�������Ľ�������
�е����죬�����Ǻڰ���������Ĵ����������һ�䣬���ܵƻ�ͨ����
ǽ�ϵ��кܶ��֩��ͼ����������Ĵ�ƽ̨�ϣ���һ��ܴ������
(statue)����Ͷ�������ģ�����ƺ����Ǻڰ������������а��
ǽ�ߵ�֩��ͼ������һ������(lever)���ƺ��ֵֹġ�
C_LONG
        );

        set( "light",0 );
        set( "exits", ([

                     "east": DROW"r18",
        ]) );
        set("search_desc",([
                   "lever": "@@to_search_lever"
          ]) );
        set("c_item_desc",(["statue":

@C_LONG
���Ǻڰ�����Ĥ�ݵķ�֮Ů��ϣ³ܽ�ĵ��񣬿�չ��˫������
����ס�˰����������������������������ӡ�
C_LONG
,
            "lever":
@C_LONG
�������б����һ��СС�ںڵ��ݿ��ڣ�������ĳ��ͨ���Ļ�
�ذɡ�
C_LONG
           ]));
        set("objects", ([
              "m7": DRO"chim"
        ]) );
        reset();
}
int to_search_lever()
{
     write("�ۡ���е�һ��������ת������������һ���ط��ˡ�\n");
     this_player()->move_player(DROW"r26","SNEAK");
     return 1;
}
