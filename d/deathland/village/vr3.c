
#include "../echobomber.h"

inherit ROOM;

int be_searched;
void create()
{
	::create();
    set_short("���˴���Ļ�����");
    set_long(
@CLong
һ�䳤��֩�����Ļ�����,�ҳ��ĺ�ȴ�ſ��������������Ľ�ӡ\��\��ӡ,���
�Ⱛ�˴����Ѿ��ͺ�ƽƽ�ضɹ�������,��˰����ǿ������ȤҲ����,����ÿ��ʮ
������л�����,��ط�����û���˻�����л�.
CLong
    );
    set("search_desc",([
        "here":"@@to_search_here",
        ]) );
    set("exits",([
                "west":Deathland"/village/v52",
             ]));
    reset();
}
string to_search_here()
{
   object *items,ob1;
   int i;
   
   if ( be_searched==1 ) return 
       "�ƺ��Ѿ����˰����﷭�䵹��س����Ѳ�һ����.\n";
   items=all_inventory(this_player());
   for(i=0;i<sizeof(items);i++) 
      if ((string)items[i]->query("name")=="broom") {
        ob1=new(Object"/key03");
        ob1->move(this_object());
        be_searched=1;
        this_player()->set_explore("deathland#9");
        return "����һ����ɨ,һ����Ѱ��ʱ��,һ�Ѻڻ�ɫ��"
        "Կ�׺�Ȼ�����������ǰ.\n";
        }
   return 
     "����Ļҳ��ܺ�,\��\��\һ������ɨ��һ��Ѱ�һ��һ��.\n";  

}
void reset()
{
   ::reset();
   be_searched=0;
}
