#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

void init()
{
  tell_object(this_player(),set_color(
    "��ѽ���ã�һ���ȳ�����������һ��ͷ��Ŀѣ��\n","HIG"));
  (CONDITION_PREFIX + "simple_poison")->apply_effect( this_player(), 10, 2 );
}
    