
#include <zeus.h>

inherit ROOM;

void create()
{
  ::create();
  set_short("����");
  set_long(@CLong
���������ŵ����·����м���ľͷ���ںӰ��ߣ�����ײ������������ (net)
�Ͽ������ԵĿ�����ĥ��ĺ��������м���������æ����һ�����Ķ���װ�ڰ峵
�ϣ��ɳ��ۿɿ�����Щ������أ�ˮ�Ƕ��������ģ���֪���� (river)���ε���
����Σ�
CLong
);
   

set("exits",([
             "up" :ZROOM"/bridge"    ]));
set("item_desc",([
	"net" : "һ��������������������ӣ���������ʵ��̫���ˣ�\n",
	"river" : "һ���ļ��ĺ�����\n"
	]));
		             
set("objects",([
             "Dun gin" : ZMOB"/Dun_gin"  ]));
reset();
 }
void init()
 {
 add_action("do_swim","swim");
 }
 int do_swim(string str)
 {    int sk;
      sk=(int)this_player()->query_skill("swimming");
      if(random(sk) < 30 ) {
      write("\n��һ����Ծ������ˮ����ȥ,ȴ�ֲ�ס�������;�,���������\n");
      tell_room(environment(this_player()),(
             this_player()->query("c_name")+"�������������������,ȴ�Ǳ��Ĵ����������˳���\n"),
             this_player() );
         return 1;
          }
      else{
      write("\n��Ŭ����ץס��ˮ�ڴ���ʯͷ������һ����ͻȻһ��ľͷ���������\n"
            "\n�������λ��ʦ�ڿ���Ц���ν�ȥ�����Ұ������Ź�\n");
      tell_room(environment(this_player()),(
              this_player()->query("c_name")+"�����������������ȴʧ������������\n"),
              this_player() );
         return 1;}
 }          