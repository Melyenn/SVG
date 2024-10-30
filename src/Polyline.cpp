#include "Polyline.h"

void Polyline::draw(){
	std::cout << "The Polyline attrs: " << '\n' <<
		"POINTS:\n";
	std::cout << this->point_list.len() << '\n';
	for (int i = 0; this->point_list.len(); ++i){
		std::cout << "X: " << this->point_list[i].x << '\n' <<
								 "Y: " << this->point_list[i].y << '\n';
	}
}

static ArrayList<Point> read_point(std::string_view str){
	ArrayList<Point> point_list;
	Point new_point;
  std::from_chars_result res;
	while(!str.empty()){
		if (str[0] == ' ' || str[0] == ','){
			str = str.substr(1);
		}
		res  = std::from_chars(str.data(), str.data() + str.size(), new_point.x); 
		str = str.substr(res.ptr - str.data());
			
		if (str[0] == ' ' || str[0] == ','){
			str = str.substr(1);
		}

		res  = std::from_chars(str.data(), str.data() + str.size(), new_point.y); 
		str = str.substr(res.ptr - str.data());
		point_list.push(new_point);
	}
	std::cout << "Read Point complete\n";
	return point_list;
}


Polyline::Polyline(Attribute *attrs, int attrs_count, BaseShape *parent)
  : BaseShape(attrs, attrs_count, parent) {
	std::cout << "Creating Polyline\n";
	for (int i = 0; i < attrs_count; ++i){
		std::string_view key = attrs[i].key;
		std::cout << key << '\n';
		std::string_view value = attrs[i].value;

		if (key == "points"){
			std::cout << "FOUNDED\n";
			std::cout << value << '\n';
			this->point_list = read_point(value);
			std::cout << "Finished read point\n";
		}
	}
	std::cout << "Finished read attributes\n";
}
