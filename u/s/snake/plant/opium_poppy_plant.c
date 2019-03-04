// opium_poppy_plant.c	��ڻ�
//
//		Lilia

#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_short("@@query_c_name");

        set("c_realname","��ڻ�");         // ��ұ��ϳɹ����ص�����
        set("realname","opium poppy");

        set("unit","��");                     // ��,��,��.�����

        set("weight", 50000);                 // ֻҪ��֤��Ұ᲻���ͺ���

        set("value", ({0, "silver"}) );       // Ұ��������Ȼ��ֵǮ��

        set("herb_file","opium_poppy.c") ;     //���������Ķ�������������
        set("herb_path","/d/healer/reagent/");   //���������Ķ�����Ŀ¼
                                              //�ǵ�������Ŀ¼
                                              //default �� /d/healer/plant

        set("skill_require",80) ;             //Ҫ�ɹ���ʶ����ֲ������֮����
        set("purified",1);                    //���ܲɼ���

        set("plant_type",0);                  //

}

string query_c_name()
{
  string* verified;
  string temp;
  string s;
  int i;
  int ok;

  if ( this_player()->query_temp("last_verify") ){
    verified=explode(this_player()->query_temp("last_verify"),"\n");
    ok = 0;
    sscanf(identify(this_object() ),"%s/%s",s,temp);
    for ( i = 0 ; i < sizeof(verified) ; i ++) {
      if ( (verified[i]) == temp )
        ok=1;
    }
  }
  else ok = 0;

  if (this_player()->query_stat("int") < 10 ) {
    set("id",({"plant","tree"}) ) ;
    set_name("a plant","����");
    set_long("���껨���κ�һ����ƺ���Щ��ͬ, ��ϧ����򵥵�С�Դ���,\n"
             "����˵��������Ȼ����\n");
    return "����";
  }
  else if ( ok==1 ) {
    set("id",({"plant","opium","poppy","opium poppy"}) );
    set_name("opium poppy","��ڻ�");
    set_long("��������ϸ�����Ľ��, ���ж�����һ����ڻ�(opium poppy),\n"
             "�������ҩ��, ������(dig)��ȥ��\n");
    return "��ڻ�";
  }
  else {
    set("id",({"plant","tree"}) );
    set_name("a plant","����");
    set_long("�������ڹ�������α��е�����֪ʶ, ���ж�����һ�ֻ���, \n"
             "������ȷ������, ����Ҫ��һ���ı�ʶ��\n");
    return "����";
  }
}
