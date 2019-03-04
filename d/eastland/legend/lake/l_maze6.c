#include "/d/eastland/legend/legend.h"

inherit LAKE+"in_lake1";
int be_search,be_open;
void create()
{
        ::create();
    set_short("��");
        set_long( 
@LONG
�㻮�����������˺����ϣ���Ŀ��������һƬ��ƽ�˾�������󺣣�Զ������
�洬�����������ظ�����������Ⱥ�����ڵز����档�����ϲ�ʱ���������㣬��
�ⷴ�������ϣ�����һ�ſ�������������ʯ�����в�����ǣ���С����Ư��Щ����
����
LONG
    );
   set("c_item_desc",([
      "����":"һ��Ư����ˮ���ϵ����� ( garbage ) ��\n"
   ]) );
   be_search=0;
   be_open=0;
    ::reset();
}
void init()
{
  ::init();
  add_action("do_search","search");
  add_action("do_open","open");
}
int do_search(string arg)
{

   if ( be_search ) return 0;
   if ( !arg || arg!="garbage" ) return 0;
   if ( !this_player()->query_temp("captain_asked") ) return 0;
   
   be_search=1;
   tell_object(this_player(),"������������ҵ�һ��Сƿ��(bottle)��\n");
   set("c_item_desc",([
      "bottle":"   һ�������ӣ������������(open)����\n"
   ]) );
   return 1;
}
int do_open(string arg)
{
    object fruit;
    if (!arg || arg!="bottle") return 0;
    if (!be_search) return 0;
    if (be_open) return 0;
        be_open=1;
    tell_object(this_player(),
       "���Сƿ�ӣ�����һ����ȶ��˵����δ�ƿ���������˳�������\n");
    tell_object(this_player(),@C_LONG
����ŮС�桹�Ļ���˵����������Ƕ���ǰ��춴��˵����峤��δ���ޣ�������
          ��˼��֮����������������㸲�峤˵�����Զ�ǵú�����һ���
          ʱ�⣬����������Ը�����ٽ�����

����ŮС�桹�Ļ����������˵���ʧ�ˡ�   
C_LONG
    );
    this_player()->set_temp("wife_asked",1);
    delete("c_item_desc/bottle");
    call_out("back",300);
    return 1;
}
void back()
{
   be_search=0;
   be_open=0;
}
void reset()
{
    be_search=0;
    be_open=0;
    delete("c_item_desc/bottle");
    ::reset();
}
