#pragma once

#include <cad/meta/metalinewidth.h>
#include <cad/meta/color.h>
#include <cad/meta/dxflinepattern.h>

namespace lc {
    class Layer;
    using Layer_CSPtr = std::shared_ptr<const Layer>;

    namespace builder {
        class LayerBuilder {
            public:
                LayerBuilder();

                const std::string& name() const;
                const MetaLineWidthByValue& lineWidth() const;
                const Color& color() const;
                DxfLinePattern_CSPtr linePattern() const;
                bool isFrozen() const;

                LayerBuilder* setName(const std::string& name);
                LayerBuilder* setLineWidth(const MetaLineWidthByValue& lineWidth);
                LayerBuilder* setColor(const Color& color);
                LayerBuilder* setLinePattern(const DxfLinePattern_CSPtr& linepattern);
                LayerBuilder* setIsFrozen(bool isFrozen);

                Layer_CSPtr build();

            private:
                bool checkValues();

                std::string _name;
                MetaLineWidthByValue _lineWidth;
                Color _color;
                lc::DxfLinePattern_CSPtr _linePattern;
                bool _isFrozen;
        };
    }
}