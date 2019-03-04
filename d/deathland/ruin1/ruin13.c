
// Deathland/ruin1/ruin13.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","�ż�");
     set_long(@Long
Long
,@CLong
һ���ƾɵ��ż� ,�����ƺ��Ѿ��ķϺܾ��� .���ϵ����ǲ�ש���� ,�����˾���
��ط��Ѿ�\��\��δ���������� .һ����ɫ��޺ֲ̦�︽�����Ե�ǽ���� ,ʹ����ط�
�����ո��Ե�ʮ�ֵĹ��� .
    �������ż���һ������ͬ ,Ȼ������ط�ȴ������޴�ĵ��� ,��\��\��\���Դ���
��������˽⵽�����ż�����ʷ .    
CLong
);
     set("item_func",([
         "statue":"look_statue",
         "description":"look_description",
         ]) );
     set("exits",([
         "east":Deathland"/ruin1/ruin23",
         ]) );
     ::reset();
}

int look_statue()
{
    write(can_read_chinese()?
          "������ʯ���ƺ������������������������ʴ ,���Ѿ��޷�����ؿ���ԭ\n"
          "����ģ���� .�����ڵ���ĵײ�����һ�����ֵ�����(description),�ƺ�\n"
          "�������ɼ������� .\n":
          "Need to work\n"
          );
    return 1;
}

int look_description()
{
    write(can_read_chinese()?
          "��������ƺ��е����ⲻ�� ,��������Ȼ�ܹ����������� :\n"
          "    ������ʯ����Ϊ�˼���ΰ���̽�ռ�������������ֵ� ,���ǳ�\��\��\n"
          "��������˼Ȫˮ����ȷλ�� .ͬʱҲ��������������ĳ�����λ��ص�֮\n"
          "�� ,���ҽ�������������ϸ���������ʦ�İ������ .\n"
          "                 ------�����ֳǹ������\n":
          "Need to work\n"
          );
    this_player()->set_explore("deathland#20");
    return 1;
}
