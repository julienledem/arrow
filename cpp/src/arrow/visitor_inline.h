// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

// Private header, not to be exported

#ifndef ARROW_VISITOR_INLINE_H
#define ARROW_VISITOR_INLINE_H

#include "arrow/array.h"
#include "arrow/status.h"
#include "arrow/type.h"

namespace arrow {

#define TYPE_VISIT_INLINE(TYPE_CLASS) \
  case TYPE_CLASS::type_id:           \
    return visitor->Visit(static_cast<const TYPE_CLASS&>(type));

template <typename VISITOR>
inline Status VisitTypeInline(const DataType& type, VISITOR* visitor) {
  switch (type.type) {
    TYPE_VISIT_INLINE(NullType);
    TYPE_VISIT_INLINE(BooleanType);
    TYPE_VISIT_INLINE(Int8Type);
    TYPE_VISIT_INLINE(UInt8Type);
    TYPE_VISIT_INLINE(Int16Type);
    TYPE_VISIT_INLINE(UInt16Type);
    TYPE_VISIT_INLINE(Int32Type);
    TYPE_VISIT_INLINE(UInt32Type);
    TYPE_VISIT_INLINE(Int64Type);
    TYPE_VISIT_INLINE(UInt64Type);
    TYPE_VISIT_INLINE(FloatType);
    TYPE_VISIT_INLINE(DoubleType);
    TYPE_VISIT_INLINE(StringType);
    TYPE_VISIT_INLINE(BinaryType);
    TYPE_VISIT_INLINE(FixedWidthBinaryType);
    TYPE_VISIT_INLINE(Date32Type);
    TYPE_VISIT_INLINE(Date64Type);
    TYPE_VISIT_INLINE(TimestampType);
    TYPE_VISIT_INLINE(TimeType);
    TYPE_VISIT_INLINE(ListType);
    TYPE_VISIT_INLINE(StructType);
    TYPE_VISIT_INLINE(UnionType);
    TYPE_VISIT_INLINE(DictionaryType);
    default:
      break;
  }
  return Status::NotImplemented("Type not implemented");
}

}  // namespace arrow

#endif  // ARROW_VISITOR_INLINE_H
