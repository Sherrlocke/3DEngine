#include "Json.h"
#include "istreamwrapper.h"
#include <fstream>

namespace nc {
	namespace json {

		bool Load(const std::string& filename, rapidjson::Document& document)
		{
			bool success = false;

			
			//<create ifstream with filename>
			std::ifstream stream (filename);
				if (stream.is_open())
				{
					rapidjson::IStreamWrapper istream(stream);
					document.ParseStream(istream);
					success = document.IsObject();
				}

			return success;
		}

		bool Get(const rapidjson::Value& value, const std::string& name, int& data)
		{
			// check if 'name' member exists and is of type
			if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsInt() == false)
			{
				return false;
			}

			// set data
			data = value[name.c_str()].GetInt();

			return true;
		}

		bool Get(const rapidjson::Value& value, const std::string& name, float& data) {
			if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsNumber() == false) {
				return false;
			}

			data = value[name.c_str()].GetFloat();
		}

		bool Get(const rapidjson::Value& value, const std::string& name, bool& data) {
			if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsBool() == false) {
				return false;
			}

			data = value[name.c_str()].GetBool();
		}

		bool Get(const rapidjson::Value& value, const std::string& name, std::string& data) {
			if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsString() == false) {
				return false;
			}

			data = value[name.c_str()].GetString();
		}

		bool Get(const rapidjson::Value& value, const std::string& name, glm::vec3& data) {
			// check if 'name' member exists and is an array with 2 elements
			if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsArray() == false || value[name.c_str()].Size() != 2)
			{
				return false;
			}

			auto& array = value[name.c_str()];
			for (rapidjson::SizeType i = 0; i < array.Size(); i++)
			{
				if (array[i].IsNumber())
				{
					data[i] = array[i].GetFloat();
				}
			}

			return true;
		}

		


	}
}