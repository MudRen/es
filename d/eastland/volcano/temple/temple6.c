#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("���������");
	set_long(
@LONG_DESCRIPTION
һ���������������յİ���������������Ķ��˵��л����ͼ����һ��
�����Ƶľ޴�����(post)���ڽ��䣬ǽ���ϵ�������\����ֵĻ��ƣ��ذ�����һ
���Ļ�ɽ��ƴ�ɵġ�
LONG_DESCRIPTION
	);
set( "exits", ([
     "northeast": OTEMP"temple10",
     "west": OTEMP"temple4",
     "south": OTEMP"temple3",
     ]) );
set("item_desc",([
    "post" : @POST
һ�����������ĺ�����ȫ��������ɫ�ģ�һ���ĺ�ɫ��Ƭ��������������
����Ŀ����㡣
POST
       ]));
set( "search_desc", ([
     "post":"@@search_post",
 ]) );
set("light",1);
reset();
}

string search_post()
{
  string str;

  if ((this_player()->query_quest_level("Dragon_box"))>1) 
    return "\n��������ϣ����Ҳ�������޳�����������ɽ硣\n\n";

  if (this_player()->query_temp("dragon_box")) {
    if (present("dragon_box",this_player())) {
      return "\n������������ÿ��������ͳ��ϸ�Ӧ���������ĸл������Ѿ��Ķ�����\n"+"��������������У��Ǹ������Ҳ���Ҫ�ˣ����ø����ϰɡ�\n\n";
     this_player()->set_temp("dragon_box",2);
    }
    return "\n�ҵı�����? �ҵ�����? \n\n";
  }
   
  if (this_player()->query_temp("gogo")) {
    str="\n�������ĵ��Ӧ�����㣺��ȥ�Ұɣ�������ĥ��ĥ��ʲ�ᡣ\n";
    return str;
  }
  
  if (this_player()->query_temp("dragon_help2")) {
    str="\n������һ�εĴܳ�����\n"+
        "\n����˵���������? �������ζ���֪��������������!\n";
    return str;
  }

  if (this_player()->query_temp("dragon_help1")) {
    str="\n�Ǻ����ִ��˳���������˵��:����ɶ��?\n"+
        "\n��˵����������ʲ�ᶫ����?\n"+
        "\n����˵���Ҹող��Ǹ������������ҵ��ı���(box)����\n"+
        "\n��˵��ร��������ˡ�\n"+
        "\n����˵����Ҫ������ร��Ҳ���˵�����Ρ�\n"+
        "\n����˵�꣬�ֻص��������ˡ�\n";
    this_player()->delete_temp("dragon_help1");
    this_player()->set_temp("dragon_help2",1);
    return str;
  }
  
  str="\nһ�������������ϴ��˳���������׼��������ʱ�����������������ǰ�棬\n"
     +"���۾�գѽգ�ģ��������������Ǻ��޵��⡣\n"
     +"\n���㲻֪����������ʱ�ᣬ\n\n"
     +"����ͻȻ���ڶ���˵�����԰���һ��æ�� ?\n\n"
     +"��˵����Ȼ���ԣ�ֻҪ������������\n\n"
     +"����˵���ںܾúܾ���ǰ��������½�������ޱ䣬�ҵ�һ���������ʧ��\n"
     +"        �ˣ�����԰��Ұ����һ�����\n\n"
     +"��˵��� ! С��һ�������ҵİ� !\n\n";
  this_player()->set_temp("dragon_help1",1);
  this_player()->set_temp("gogo",1);
  call_out("forget",60,this_player());
  return str;
}

int forget(object who)
{
 this_player()->delete_temp("gogo");
 write("\n\n����һ���������뵽��������Ͳ�֪����������Ҫ����ɶ��\n\n");
  return 1;
}
