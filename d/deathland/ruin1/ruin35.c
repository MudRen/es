
// Deathland/ruin1/ruin35.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","�ż�");
     set_long(@Long
Long
,@CLong
�������㷢������ط���һ��ƽ��������ס�ķ��� ,�������ż������ĵط���
ȫ��ͬ .���Ե����������ס������ .�������\��\�������˽⵽����ط�������һ
���൱����ѧ�� ,��Ϊ����ط�������Ҫ�������û�� .
CLong
);
     set("item_func",([
          "books":"look_books",
          "book":"look_book",
          ]) );
     set("search_desc",([
          "floor":"@@search_floor"
          ]) );
     set("objects",([
         "ranger":Deathland"/monster/ranger",
         ]) );
     set("exits",([
         "south":Deathland"/ruin1/ruin34",
         ]) );
     ::reset();
}

int look_books()
{
    write(can_read_chinese()?
          "һ����ɽ ,\��\��\�����ҳ�һЩ���õ�֪ʶ ,������δ���Щ���з���\n"
          "����Ҫ���� ?\n":
          "NEEd to work");
    return 1;    
}

int look_book()
{
    write(can_read_chinese()?
          "����Ҫ����һ������ ?\n":
          "Which book do you want to look ?\n"
         );
    return 1;      
}

string search_floor()
{
     object *items,who;
     int i;
     
     who=this_player();  
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
      if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
        if ( items[i]->query("quest_action/pepper_find") ) {
          items[i]->set("quest_item/summon_pepper",1);
          return "����Ѱ�ذ�ʱ, ������һƿ������.\n";
          } 
     return "�ذ��ƺ��е����, �����޷�ȷ��.\n";
}
