// Deathland/holyplace/h16.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);	
  set_short(" A strange place","����������Ʈ�촦");
  set_long("need work .\n",
"һ�������ĵ�������,�Ĵ��ĺ�Ӱ������Ϣ��������Ϯ����.����ļž����˸е�����,\n"
"���㲻��������Ҫ����һЩ����.û�з���,û��ˮ��,�������޷������Լ��ĽŲ���,�㲻\n"
"�������Լ�����һ�����޵ĵط�.�����ҰԽ��ԽС,�ƺ�����۾���һЩ��ɫ��\"��\"��ס\n"
"������.�����Σ�յĵط�,�������߾���,��Ϊ��ʱ���п��ܴӺڰ����߳�а�������.\n"
"����ط��ƺ��Ǹ���յ�����,���������������Ǻ����ұ�,���ߵ�Ψһ����Ҳխխ��\n"
".������ֵ���,��ط��ƺ���������(light).\n"
);

set("c_item_desc",([
    "fog":"@@to_look_fog",
    "light":"@@to_look_light",
    "plate":"@@to_look_plate",
    ]) );
set("exits",([
             "east":Deathland"/holyplace/h15",
             ]));
reset();
}

string to_look_fog()
{
     return "������?�㻳����,���ܺ�����ؿ���һЩ��������Ʈɢ�������Χ.\n"
            "\��\��\��һ��а�������,���ܸо�������а��ĳɷݲ�������.\n" ;
}

string to_look_light()
{
    return "�ǵ�΢΢�������ƺ��������ߵ��������,��ϸһ��,ԭ�����ߵ��ұ�����.\n"
           "��һ��ƽ̨(plate).\n";
}

string to_look_plate()
{
      return "һ��СС��ƽ̨,������춵���̫��,�������޴�������ؿ������������ᶫ��.\n";
}
