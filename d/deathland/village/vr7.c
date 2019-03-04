
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    //set("light",1);
    set_short("The beautiful building","�����Ľ���");
    set_long(@Long
Long
,@CLong
һ�������Ľ�����,����һ������������ħ��ʦ���ɾ�ס�ĵط�.�������,����װ
�εĸ����û�,������ۼ,����֮��,��������ס��Ŀ��Ľ���Ī���һ�������(closet)
��,����֮��,��һ��\��\��Ʒ��������伫�����,�Ǿ���һ�ź���С���ӻ��Ļ���(paint
ing),�����⻭���ر�Ĵ�,ֻҪ����������,��Ͳ��ò�������.
CLong
    );
    set("c_item_desc",([
        "closet":"һ�������,����Ĳ��龪�˵��ǰٷ�֮��ʮ�Ŷ��ǹ�����,һ\n"
                 "��ʧ���ѾõĹ�������,�Ѿ�û������ʶ��.\n",
        "painting":"����һֻ�����Ļ���,����׾�ӵıʷ����˷�Ц\n",
        "bottle":"@@to_look_bottle",
        ]) );
    set("search_desc",([
       "closet":"@@to_search_closet",
       "painting":"@@to_search_painting",
        ]) );
    set("exits",([
                "east":Deathland"/village/v14",
             ]));
    set("objects",([
        "impmage":Monster"/impmage",
        ]) );
    reset();
}

string to_look_bottle()
{
  this_player()->set_explore( "deathland#27" );
  return "һ��������Ĳ���ƿ,��ܾ���Ϊ��һ��СС�Ĳ���ƿ����������ħ��.\n";     
}

string to_search_closet()
{
      return "����һ��ѵ��鼮�⻹��һ��СС�Ŀ�ƿ��.\n";
}

string to_search_painting()
{
    return "�������ܹ���������?һ�����������ͨ��\��\��һ����ֵİ�ť.\n";
}

