//Deathland/holyplace/h02.c
//Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set_short(" Drawf holy place ","����ʥ�صļ�̳");
  set_long(@Long
Long
,@CLong
���������ܸо���һ����ʥ��ׯ�ϵ�����,������͵������ʹ����ط���������
�͵�����,��Ŀǰ��λ�����ڰ���ʥ�صļ�̳.���ĸ��ܴ��Բ���������ĸ�����,�м�
��һ����ļ�̳,���и��޴������������,���Ե��ǰ��˵���,Yang.����,����ʮ��
�����ܵ��һ���һ��Բ��Χ������̳,Ȼ����ȴ���������Щ��Ļ��ܴ���,�෴��
��Щ��������͵ĸо�.�Ϸ���һ���������ص�С��,��\��\��\Ӧ��ȥ����.
CLong
);

set("c_item_desc",([
    "fire":"ʮ�������ܵ��һ�.��һ��Բ��Χ������̳\n",
    "statue":"һ���޴������.\n",
    "altar":"һ������һ��ļ�̳.\n"
    ]) );
set("exits",([
             "south":Deathland"/holyplace/h03",
             "west":Deathland"/holyplace/h05",
             "east":Deathland"/holyplace/r05",
             ]));

set("objects",([
    "guard":Monster"/guard08",
    ]) );
reset();

}
